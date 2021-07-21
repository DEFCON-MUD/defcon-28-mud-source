#include <type.h>

inherit cont "/std/container";
inherit "/std/modules/m_block_exits";

static mapping exits, hidden_exits, areas, items;
static int last_exit, weather, light, pk, nokill;
static int * coords, * dimensions, * map_start;


string dark_msg, domain_name, exit_ansi, exit_ansi2;
string long_ansi, short_ansi;
int door_closed;
int locked;
string key;

void setup(void);

int is_room(void) {
   return 1;
}

void set_coords(int * flag) {
   coords = flag;
}

int *get_coords(void) {
   return coords;
}

void set_dimensions(int * flag) {
   dimensions = flag;
}

int *get_dimensions(void) {
   if (!dimensions) {
     return ({ 12, 16 });
   }
   return dimensions;
}

void set_mapstart(int * flag) {
   map_start = flag;
}

int *get_mapstart(void) {
   if (!map_start) {
     return ({ 0, 0 });
   }
   return map_start;
}

void set_light(int flag) {
   light = flag;
}

void set_domainname(string flag) {
   domain_name = flag;
}

string get_domainname(void) {
  if (!domain_name) {
      domain_name = explode(this_environment()->file_name(), "/")[1];
  }
  return domain_name;
}

private int object_is_lighted(object obj) {
   object *objs;
   int i, dim, l;

   if (obj->is_living()) {
      objs = obj->query_inventory();
      for (i = 0, dim = sizeof(objs); i < dim; i++) {
         if (objs[i]->functionp("query_lit")) {
            if (objs[i]->query_lit()) {
               return 1;
            }
         }
      }
   }

   if (obj->functionp("query_lit")) {
      return obj->query_lit();
   }

   return 0;
}

int is_dark(void) {
   object* objs;
   int i, x;

   if (DARK_D->is_dark(this_environment()->file_name())) {
      return 1;
   } else if (light) {
      return 0;
   }

   if (is_container()) {
      objs = query_inventory();
      for (x = sizeof(objs) -1; x >= 0; x--) {
         if (object_is_lighted(objs[x])) {
            return 0;
         }
      }
   }

   return 1;
}

string query_dark_msg(void) {
   if (!dark_msg) {
      return "It is too dark to see here.\n";
   }
   return dark_msg;
}

void set_dark_msg(string str) {
   dark_msg = str;
}

void set_exit_ansi(string str) {
   exit_ansi = str;
}

string query_exit_ansi(void) {
   string exit_color;
   exit_color = COLOR_D->query_exit(this_environment()->file_name());
   if (!exit_ansi) {
     if(!exit_color) {
        return "%^HWHITE%^";
     } else {
        exit_color = "%^" + exit_color + "%^";
        return exit_color;
     }
   }
   return exit_ansi;
}

string query_exit_ansi2(void) {
   string exit_color;
   exit_color = COLOR_D->query_exitdir(this_environment()->file_name());
   if (!exit_ansi2) {
     if(!exit_color) {
       return "%^RESET%^";
     } else {
        exit_color = "%^" + exit_color + "%^";
        return exit_color;
     }
   }
   return exit_ansi2;
}

void set_exit_ansi2(string str) {
   exit_ansi2 = str;
}

void set_short_ansi(string str) {
   short_ansi = str;
}

string query_short_ansi(void) {
   string short_color;
   short_color = COLOR_D->query_short(this_environment()->file_name());
   if (!short_ansi) {
     if(!short_color) {
       return "%^GREEN%^";
     } else {
       short_color = "%^" + short_color + "%^";
       return short_color;
     }
   }
   return short_ansi;
}

void set_long_ansi(string str) {
   long_ansi = str;
}

string query_long_ansi(void) {
   string long_color;
   long_color = COLOR_D->query_long(this_environment()->file_name());
   if (!long_ansi) {
     if (!long_color) {
       return "%^RESET%^";
     } else {
       long_color = "%^" + long_color + "%^";
       return long_color;
     }
   }
   return long_ansi;
}

void set_weather(int flag) {
   weather = flag;
}

int query_weather(void) {
   return weather;
}

void set_pk(int flag) {
   pk = flag;
}

void set_nokill(int flag) {
   nokill = flag;
}

int query_pk(void) {
  if (!pk) {
    return 0;
  }
  return pk;
}

int query_nokill(void) {
  if (!nokill) {
    return 0;
  }
  return nokill;
}

void add_area(string str) {
   areas += ([str:1]);
}

int query_in_area(string str) {
   if (areas[str]) {
      return 1;
   } else {
      return 0;
   }
}

string *query_areas(void) {
   return map_indices(areas);
}

void set_exits(mapping ex) {
   exits = ex;
}

void set_hidden_exits(mapping ex) {
   hidden_exits = ex;
}

void add_exit(string direction, string file) {
   exits += ([direction:file]);
}

void remove_exit(string direction) {
   exits[direction] = nil;
}

void add_hidden_exit(string direction, string file) {
   hidden_exits += ([direction:file]);
}

void remove_hidden_exit(string direction) {
   hidden_exits[direction] = nil;
}

mapping query_exits(void) {
   return exits;
}

mapping query_hidden_exits(void) {
   return hidden_exits;
}

string *query_exit_indices(void) {
   return map_indices(exits);
}

string *query_hidden_exit_indices(void) {
   return map_indices(hidden_exits);
}

string query_exit(string direction) {
   return exits[direction];
}

string query_hidden_exit(string direction) {
   return hidden_exits[direction];
}

/* Attempts to find the actual room object attached to a given exit.
  Will compile it if necessary.
  Cerihan - 3/13/09
*/
object query_exit_room(string direction) {
   string exit;
   object qroom;

   exit = query_exit(direction);
   if (!exit) {
      return nil;
   }

   qroom = find_object(exit);
   if (!qroom) {
      qroom = compile_object(exit);
   }

   return qroom;
}

string query_desc(varargs int brief) {
   string text;
   mixed *tmp_array;
   mixed *tmp_colors;
   string tmp_message;
   int count, size, mxp, gmcp, vnum, anum;
   int tmp_x, tmp_y, tmp_z;
   int ansi;
   object *inventory;
   mapping compacted_inv;

   if (!brief) {
      brief = 0;
   }
   mxp = this_player()->query_mxp();
   gmcp = this_player()->gmcp();
   ansi = this_player()->query_ansi();
   
   text = "";
   
  /* Start GMCP */
  if (gmcp == 1) {
    string gmcp_json;
    string area;
    string *area_list;
    int *tmp_coords;
    vnum = VNUM_D->vnum();
    anum = VNUM_D->anum();

    gmcp_json = "{ \"num\": " + vnum + ", ";
    gmcp_json += "\"name\": \"" + this_environment()->query_short() + "\", ";

    area_list = query_areas();
    if (sizeof(area_list) < 1) {
      area = "unknown";
    } else {
      area = area_list[0];
    }

    if (area) {
      gmcp_json += "\"area\": \"" + area + "\", ";
    }

    gmcp_json += "\"zone\": \"" + (explode(this_environment()->file_name(),"/")[1]) + "\", ";
    gmcp_json += "\"details\": \"\", ";
    gmcp_json += "\"Environment\": \"Urban\", ";

    /* core co-ordinates */
    if (explode(this_environment()->file_name(),"/")[1] == "core") {
          gmcp_json += "\"coord\": \"" + anum + "," + this_environment()->property("x") + "," + this_environment()->property("y") + "," + this_environment()->property("z") + "\", ";  
    }

    /* woodland co-ordinates */
    /* if (explode(this_environment()->file_name(),"/")[1] == "woodland") { */
    /*  gmcp_json += "\"coord\": \"" + anum + "," + tmp_coords[0] + ",-" + tmp_coords[1] + ",0\", ";  */
    /* } */

    /* sewer co-ordinates */
    if (explode(this_environment()->file_name(),"/")[1] == "sewer") {
      string tmp_file;
      string tmp_letter;
      string *tmp_array;
      int tmp_x, tmp_y;
      tmp_file = explode(explode(this_environment()->file_name(),"/")[3], ".")[0];
      sscanf(tmp_file, "%d-%s", tmp_x, tmp_letter);
      switch (tmp_letter) {
        case "a":
          tmp_y = 1;
          break;
        case "b":
          tmp_y = 2;
          break;
        case "c":
          tmp_y = 3;
          break;
        case "d":
          tmp_y = 4;
          break;
        case "e":
          tmp_y = 5;
          break;
        case "f":
          tmp_y = 6;
          break;
        case "g":
          tmp_y = 7;
          break;
        case "h":
          tmp_y = 8;
          break;
        case "i":
          tmp_y = 9;
          break;
        case "j":
          tmp_y = 10;
          break;
        case "k":
          tmp_y = 11;
          break;
        case "l":
          tmp_y = 12;
          break;
        case "m":
          tmp_y = 13;
          break;
        case "n":
          tmp_y = 14;
          break;
        case "o":
          tmp_y = 15;
          break;
        case "p":
          tmp_y = 16;
          break;
        case "q":
          tmp_y = 17;
          break;
        case "r":
          tmp_y = 18;
          break;
        case "s":
          tmp_y = 19;
          break;
        default:
          tmp_y = 0;
      }
      /* evilmog screwed up and reversed x and y when he build the areas */
      gmcp_json += "\"coord\": \"" + anum + ",-" + tmp_y + "," + tmp_x + ",0\", ";
    }

    /* dungeon co-ordinates */
    if (area == "dungeon") {
      string tmp_file;
      string tmp_letter;
      int tmp_x, tmp_y;
      tmp_file = explode(explode(this_environment()->file_name(),"/")[3], ".")[0];
      sscanf(tmp_file, "%d-%s", tmp_x, tmp_letter);
      switch (tmp_letter) {
        case "a":
          tmp_y = 1;
          break;
        case "b":
          tmp_y = 2;
          break;
        case "c":
          tmp_y = 3;
          break;
        case "d":
          tmp_y = 4;
          break;
        case "e":
          tmp_y = 5;
          break;
        case "f":
          tmp_y = 6;
          break;
        case "g":
          tmp_y = 7;
          break;
        case "h":
          tmp_y = 8;
          break;
        case "i":
          tmp_y = 9;
          break;
        case "j":
          tmp_y = 10;
          break;
        case "u":
          tmp_y = 11;
          break;
        case "v":
          tmp_y = 12;
          break;
        default:
         tmp_y = 1000;
       }
       /* evilmog screwed up and reversed x and y when he build the areas */
       gmcp_json += "\"coord\": \"" + anum + "," + tmp_y + ",-" + tmp_x + ",0\", ";
    }
    gmcp_json += "\"map\": \"\", ";  

    if (!exits || map_sizeof(exits) == 0) {
      gmcp_json += "\"exits\": { }, ";
    } else {
    /* insert exit lookup code here, calculate all vnums */
    /*  "exits":    {    "n":    12344,    "se":    12336    }, */
      gmcp_json += "\"exits\": { ";
      for (count = 0; count < map_sizeof(exits); count++) {
        if (count < (map_sizeof(exits) - 1)) {
          gmcp_json += "\"" + map_indices(exits)[count] + "\": ";
          gmcp_json += "\"" + VNUM_D->vnum_lookup(query_exit(map_indices(exits)[count])) + "\"";
          gmcp_json += ", ";
        } else {
          gmcp_json += "\"" + map_indices(exits)[count] + "\": ";
          gmcp_json += "\"" + VNUM_D->vnum_lookup(query_exit(map_indices(exits)[count])) + "\"";
        }
      }
      gmcp_json += " }"; 
    }
    gmcp_json += " }";
    this_player()->send_gmcpsubnegotiation("Room.Info " + gmcp_json );
  }

  /* END GMCP */

  if (is_dark()) {
      if (this_player()->query_race_object()->has_darkvision()) {
      } else if (query_wizard(this_player())) {
      } else {
         return query_dark_msg();
      }
   }

   
   /* Short Description Block After MXP */

  if (ansi == 1) {
    text += query_short_ansi();
  }
   
  if (mxp == 1) {
    text += "%^MXP_LSM%^";
    text += "<RName>";
  }
  if (!ansi) {
    text += ANSI_D->strip_colors(query_short());
  } else if (ansi == 1) {
    text += query_short();
  }
  
  if (mxp == 1) {
    text += "</RName>";
  }
  if (ansi == 1) {
    text += "%^RESET%^\n\n";
  }
  
  /* Long Description Block After MXP */
  if (ansi == 1) {
    text += query_long_ansi();
  }
  if (mxp == 1) {
    text += "<RDesc>";
  }
  if (!ansi) {
    text += ANSI_D->strip_colors(query_long());
  } else if (ansi == 1) {
    text += query_long();
  } 

  if (mxp == 1) {
    text += "</RDesc>";
  }
  if (ansi == 1) {
    text += "%^RESET%^\n";
  }

   /* Exit Block */
  

   if (!exits || map_sizeof(exits) == 0) {
    text += "";
   } else {
      text += query_exit_ansi() + "\nExits:" + "%^RESET%^ " + query_exit_ansi2();
      if (mxp == 1) {
        text += "<RExits>";
      }
      for (count = 0; count < map_sizeof(exits); count++) {
          if (count < (map_sizeof(exits) - 1)) {
              if (mxp == 1) {
                text += "<Ex>";
              }
              text += map_indices(exits)[count];
              if (mxp == 1) {
                text += "</Ex>";
              }
                text += ", ";
          }
          else {
              if (mxp == 1) {
                text += "<Ex>";
              }
              text += map_indices(exits)[count];
              if (mxp == 1) {
                text += "</Ex>";
              }
          }
      }
   }
   if (mxp == 1) {
     text += "</RExits>%^MXP_LLM%^";
   }
   text += "%^RESET%^\n";

   inventory = query_inventory();

   /* There is something in the room */
   if (inventory && sizeof(inventory) > 1) {
      string desc, dshort, dname, iid;

      compacted_inv = ([]);

      text += "\nYou see:\n";

      for (count = 0; count < sizeof(inventory); count++) {
         if (!inventory[count]->is_living()) {
            if (mxp == 1) {
                string iid, ishort;
                iid = inventory[count]->query_id();
                ishort = inventory[count]->query_short();
                desc = "%^MXP_LSM%^<send href=\"look " + iid + "|get " + iid + "\">%^OBJ_BRIEF%^" + ishort + "</send>%^MXP_LLM%^%^RESET%^";
            } else {
              desc = "%^OBJ_BRIEF%^" + capitalize(
                 inventory[count]->query_short()) + "%^RESET%^";
            }
         } else {
            mixed x;
            string pc;
            int mob, plvl, mlvl, pdiff;

            if (inventory[count] == this_player()) {
               continue;
            }
            dshort = inventory[count]->query_short();
            dname = inventory[count]->query_name();
            iid = inventory[count]->query_id();
            x = inventory[count]->query_idle();
            mob = 0;
            if (inventory[count]->is_player()) {
               pc = "%^PLAYER%^";
            } else {
               mob = 1;
               pc = "%^NPC_FRIENDLY%^";
               plvl = this_player()->query_level();
               mlvl = inventory[count]->query_level();
               pdiff = plvl - mlvl;
               switch (pdiff) {
                 case 0:
                   pc = "%^RESET%^";
                   break;
                 case 1:
                   pc = "%^CYAN%^";
                   break;
                 case 2:
                   pc = "%^GREEN%^";
                   break;
                 case 3..9:
                   pc = "%^HGREEN%^";
                   break;
                 case -1:
                   pc = "%^YELLOW%^";
                   break;
                 case -2:
                   pc = "%^RED%^";
                   break;
                 case -3..-9:
                   pc = "%^HRED%^";
                   break;
                 default:
                   pc = "%^RESET%^";
                   break;
               }
            }

            if (x && x > 60) {
               desc = "" + pc + capitalize(dshort) +
                  " [idle" + fmt_time(inventory[count]->query_idle()) +
                  "]  " + "%^RESET%^";
            } else {
              if (mxp == 1) {
               desc = "%^MXP_LSM%^<send href=\"look " + iid + "|kill " + iid + "\">" + pc + capitalize(dshort) +
                 "</send>%^MXP_LLM%^%^RESET%^";
              } else {
               desc = "" + pc + capitalize(dshort) +
                 "%^RESET%^";
              }
            }
         }
#ifdef LONG_ROOM_INV
         text += desc + "\n";
      }
#else
         if (!compacted_inv[desc]) {
            compacted_inv[desc] = ({ });
         }
         compacted_inv[desc] += ({ inventory[count] });
      }

      if (compacted_inv && map_sizeof(compacted_inv)) {
         string *keys;
         int amount;

         keys = map_indices(compacted_inv);

         for (count = 0, size = sizeof(keys); count < size; count++) {
            amount = sizeof(compacted_inv[keys[count]]);

            if (amount == 1) {
               text += keys[count];
            } else {
               text += keys[count] + " [x" + amount + "]";
            }
            text += "\n";
         }
      }
#endif
   }
   return text;
}

void set_items(string id, varargs mixed args ...) {
   string description;
   int i;

   if (!items) {
      items = ([]);
   }

   description = args[sizeof(args) - 1];
   items[id] = description;

   if (sizeof(args) > 1) {
      for (i = 0; i < sizeof(args) - 1; i++) {
         items[args[i]] = description;
      }
   }
}

void add_item(string id, varargs mixed args ...) {
   string description;
   int i;

   if (!items) {
      items = ([]);
   }

   description = args[sizeof(args) - 1];
   items[id] = description;

   if (sizeof(args) > 1) {
      for (i = 0; i < sizeof(args) - 1; i++) {
         items[args[i]] = description;
      }
   }
}

void remove_item(string id) {
   mapping temp_desc;
   int size, i;
   string description, *indices, *values;

   if (!items) {
      items = ([]);
   }

   temp_desc = ([]);
   description = items[id];
   size = map_sizeof(items);
   values = map_values(items);
   indices = map_indices(items);

   for (i = 0; i < size; i++) {
      if (description != values[i]) {
         temp_desc[indices[i]] = values[i];
      }
   }
   items = ([]);
   items = temp_desc;
}

string *query_item_ids(void) {
   if (!items) {
      items = ([]);
   }
   return map_indices(items);
}

string *query_items(void) {
   if (!items) {
      items = ([]);
   }
   return map_indices(items);
}

string query_item(string item) {
   if (!items) {
      items = ([]);
   }
   if (items[item][0..0] == "#") {
      return call_other(this_object(), items[item][1..]);
   }

   return items[item];
}

/*-------------------------------------------------------------------
  sends a message to the room, designed specificly for non-living
  objects to communicate with the room
*/
void message_room(object originator, string str) {
   int i, sz;
   object *inventory;

   inventory = query_inventory();

   if (!inventory && sizeof(inventory) > 0) {
      return;
   }
   for (i = 0, sz = sizeof(inventory); i < sz; i++) {
      if (!inventory[i]) {
    continue;
      }
      if (originator != inventory[i]) {
    if (inventory[i]->is_living()) {
       inventory[i]->message(str);
    }
    inventory[i]->outside_message(str);
      }
   }
}

void tell_room(object originator, string str, varargs mixed obj ...) {
   int i;
   object *inventory;

   inventory = query_inventory();

   if (!inventory && sizeof(inventory) > 0) {
      return;
   }
   for (i = 0; i < sizeof(inventory); i++) {
      if (!inventory[i]) {
         continue;
      }
      if (originator != inventory[i] && member_array(inventory[i], obj) == -1) {
         if (inventory[i]->is_living() &&
            (!originator ||
            !inventory[i]->query_ignored(originator->query_name()))) {

            if (previous_object()->base_name() == "/cmds/player/say") {
               inventory[i]->message(capitalize(str), 1);
            } else {
               inventory[i]->message(capitalize(str));
            }
         }
         inventory[i]->outside_message(capitalize(str));
      }
   }
}

int check_block_object(object obj, string dir, object who) {
   if (obj->is_blocking(dir) && obj->do_block(who)) {
      obj->other_action(obj, obj->query_block_action(), who, dir);
      return 1;
   }
   return 0;
}

string body_exit(object who, string dir) {
   int i, max;
   string error, lname, aname;
   object room, *inventory;

   if (!query_exit(dir) && !query_hidden_exit(dir)) {
      write("You can't go " + dir + ".\n");
      if (this_player()->gmcp() == 1) {
        this_player()->send_gmcpsubnegotiation("Room.WrongDir \"" + dir + "\"");
      }
      return nil;
   }

   lname = who->query_Name();
   aname = lname;
   if (!lname) {
      /* Generic-named NPCs */
      lname = "The " + who->query_id();
      aname = "A " + who->query_id();
   }

   inventory = query_inventory();

   if (query_exit(dir) || query_hidden_exit(dir)) {
      if (check_block_object(this_object(), dir, who)) {
         return nil;
      }
   }

   /* there is a normal exit */
   if (query_exit(dir)) {
      max = sizeof(inventory);

      for (i = 0; i < max; i++) {
         if (check_block_object(inventory[i], dir, who)) {
             return nil;
         }
      }

      if (query_exit(dir)[0] == '#') {
         call_other(this_object(), query_exit(dir)[1..]);
         return nil;
      }

      event("body_leave", who);
      tell_room(who, lname + " leaves " + dir + ".\n");
      error = catch(who->move(query_exit(dir)));
      if (who->is_player()) {
    last_exit = time();
      }
   } else if (query_hidden_exit(dir)) {
      max = sizeof(inventory);
      for (i = 0; i < max; i++) {
         if (check_block_object(inventory[i], dir, who)) {
             return nil;
         }
      }

      if (query_hidden_exit(dir)[0] == '#') {
         call_other(this_object(), query_exit(dir)[1..]);
         return nil;
      }

      event("body_leave", who);
      tell_room(who, lname + " leaves " + dir + ".\n");
      error = catch(who->move(query_hidden_exit(dir)));
      if (who->is_player()) {
         last_exit = time();
      }
   }

   if (error) {
      if (query_wizard(who) == 1) {
         return "\nConstruction blocks your path.\n" + "Error: " + error;
      } else {
         return "\nConstruction blocks your path.\n";
      }
   }

   if (who->is_player() || who->is_possessed()) {
      call_other(this_player(), "do_look", this_environment());
   }

   room = who->query_environment();
   room->event("body_enter", who);
   room->tell_room(who, aname + " enters.\n");
   return nil;
}

void destruct(void) {
   move_or_destruct_inventory();

   EVENT_D->unsubscribe_event("clean_up");
   ::destruct();
}

void event_clean_up(void) {
   int i, max;
   object *inventory;

   if (time() - last_exit < 60 * 15) {
      return;
   }

   inventory = query_inventory();
   max = sizeof(inventory);
   for (i = 0; i < max; i++) {
      if (!inventory[i]) {
         continue;
      }
      if (inventory[i]->is_player() || inventory[i]->is_possessed() ||
         inventory[i]->no_cleanup()) {
         return;
      }
   }

   destruct();
}

void upgraded(void) {
   ::upgraded();
   /*
    * special for rooms, ::upgraded() will only call
    * setup in clones, while blueprints of rooms are often used
    * and will also require setup.
    */

   if (clone_num() == 0) {
      setup();
   }
}

void create(void) {
   cont::create();
   add_event("body_enter");
   add_event("body_leave");
   add_event("body_look");
   add_event("body_look_at");
   add_event("room_message");
   if (!WORLD_PERSIST) {
     EVENT_D->subscribe_event("clean_up");
   }
   exits = ([]);
   hidden_exits = ([]);
   areas = ([]);
   items = ([]);
   last_exit = 0;
   light = 1;
   setup();
}

string look_door() {
   if (!door_closed) {
      return "The door is open.";
   }
   return "The door is closed.";
}

int open_door() {
   if (locked && (!LOCK_D->is_unlocked(this_environment()->file_name())) ) {
      write("The door is locked.\n");
      tell_room(this_player(), this_player()->query_Name() +
         " fiddles with the locked door.\n");
   } else if (LOCK_D->is_locked(this_environment()->file_name())) {
      write("The door is maglocked........\n");
      tell_room(this_player(), this_player()->query_Name() +
         " fiddles with the locked door....\n");
   } else if (door_closed) {
      door_closed = 0;
      write("You open the door.\n");
      tell_room(this_player(), this_player()->query_Name() +
         " opens the door.\n");
   } else {
      write("The door is already open.\n");
      tell_room(this_player(), this_player()->query_Name() +
         " fiddles with the open door.\n");
   }
   return 1;
}

int close_door() {
   if (door_closed) {
      write("The door is already closed.\n");
      tell_room(this_player(), this_player()->query_Name() +
         " fiddles with the closed door.\n");
   } else {
      door_closed = 1;
      write("You close the door.\n");
      tell_room(this_player(), this_player()->query_Name() +
         " closes door.\n");
   }
   return 1;
}

int has_key(string str) {
   object obj;

   obj = this_player()->present(str);

   if (obj) {
      return 1;
   }
   return 0;
}

int lockpick_door() {
  if (!locked) {
    locked = 1;
    door_closed = 1;
    return 1;
  }
  if (locked) {
   locked = 0;
   door_closed = 0;
   return 1;
  }
}

int unlock_door() {
   if (!locked && LOCK_D->is_unlocked(this_environment()->file_name())) {
      write("The door is already unlocked.\n");
      tell_room(this_player(), this_player()->query_Name() +
         " fiddles with the door.\n");
   } else if (has_key(key)) {
      write("You unlock the door.\n");
      tell_room(this_player(), this_player()->query_Name() +
         " unlocks the door.\n");
      locked = 0;
   } else {
      write("You can't find the key for that door.\n");
      tell_room(this_player(), this_player()->query_Name() +
         " fiddles with the door.\n");
   }
}

int lock_door() {
   if (locked) {
      write("The door is already locked.\n");
      tell_room(this_player(), this_player()->query_Name() +
         " fiddles with the door.\n");
   } else if (LOCK_D->is_unlocked(this_environment()->file_name())) {
      write("The door is remotely unlocked");
      tell_room(this_player(), this_player()->query_Name() +
         " fiddles with the door.\n");
   } else if (!door_closed) {
      write("The door is open, you can't lock it when it's open.\n");
      tell_room(this_player(), this_player()->query_Name() +
         " fiddles with the door.\n");
   } else if (has_key(key)) {
      write("You lock the door.\n");
      tell_room(this_player(), this_player()->query_Name() +
         " locks the door.\n");
      locked = 1;
   } else {
      write("You can't find the key for that door.\n");
      tell_room(this_player(), this_player()->query_Name() +
         " fiddles with the door.\n");
   }
}

int enter_door() {
   if (LOCK_D->is_unlocked(this_environment()->file_name())) {
      return 1;
   } else if (!door_closed) {
      return 1;
   }  else if (has_key(key)) {
      return 1;
   } else if (LOCK_D->is_locked(this_environment()->file_name())){
      write("The door is maglocked and refuses to open for you......");
      tell_room(this_player(), this_player()->query_Name() +
         " walks right into the closed door, with a SMACK.\n");
   } else {
      write("The door is closed.  You need the appropriate access key to enter.\n");
      tell_room(this_player(), this_player()->query_Name() +
         " walks right into the closed door, with a SMACK.\n");
   }
   return 0;
}


int do_block(object who) {
   if (enter_door()) {
      return 0;
   }
   return 1;
}
