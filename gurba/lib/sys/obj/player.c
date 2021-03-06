/* Player object. By Fudge */

#include <channel.h>
#include <type.h>
#include <limits.h>
#include <telnet.h>

inherit con "/std/container";
inherit bod "/std/body";
inherit "/sys/lib/runas";
inherit "/std/modules/m_messages";
inherit "/sys/lib/editor";
inherit "/std/modules/m_autoload_string";
inherit "/std/modules/m_language";
inherit "/std/body/skills";
inherit cmd "/sys/lib/modules/m_cmds";
inherit history M_HISTORY;
inherit serialize M_SERIALIZE;

static object user; 		/* This players user object */
static string input_to_func;	/* The function we're redirecting input to */
static mixed input_to_arg;      /* Optional extra argument(s) to the function 
                                   we're redirecting input to */
static object input_to_obj;	/* The object we're redirecting input to */
static int linkdead;		/* Are we linkdead? */
static int quitting;		/* Are we in the process of quitting? */
static int timestamp;		/* Last time we got input */
static int more_line_num;	/* How far in the file we're more'ing are we */
static object more_caller;	/* Who called more in us 
					(so we can call it back when done */
static string *more_lines;	/* All the lines in the file we're more'ing */
string last_tell;		/* Who did we get a tell from last? */
static int color_more;		/* Flag to specify color more */

string real_name;		/* This players real name */
string email_address;		/* The email address */
string website;			/* Players webpage */
mapping environment_variables;	/* The environment variables of the player */
string title;			/* The title */
string password;		/* The password */
string *cmd_path;		/* The path which is searched for commands */
string *channels;		/* Channels we're listening to */
string *ignored;		/* the users we are ignoring */
mapping alias;			/* The players aliases */
int last_login;			/* The last login */
mapping guilds;			/* The guilds the player is a member of. 
					The values are the guild title. */
int ansi;               /* if ansi is on or off */
int lastpaid;		/* sets last paid */
int lastmined;		/* sets last mined */
string minelocation; /* sets room of last mined */
int minestate; /* sets if the player is mining or not */
int cryptofail; /* sets north mine failures */
int deathproof;		/* sets death proof */
int cheater;		/* tracks cheat status */
int q7_tracker;		/* tracks status of quest 7 */
int mxp;		/* mxp mode */
int ga;
mapping custom_colors;  /* custom color symbols for this player */
int terminal_height;    /* how many lines of text in more etc. */
int terminal_width;     /* maximum line width before wrapping to next line */
int lives;              /* number of times you've been cloned */
string prompt;          /* user definable prompt */
string start_room;      /* the room you start in on logon */
string death_room;      /* the room you come back to life in */
string quit_message;    /* the message shown when user quits */
int hidden;             /* hide login from players */
int autoload;           /* 1 to keep our equipment after quitting */
int save_on_quit;       /* 1 to login to room you quit from */
int debug_commands;     /* 1 for debugging of commands */
int verbose_errors;     /* 1 for longer error codes */
int display_caught;     /* 1 to show caught runtime errors */
static mixed menu_data;		/* temp storage for menu system */
int muzzle;			/* if 0 we are allowed to shout. */
int *woodland_kills;   /* Tracks killed woodland critters */
int *cypher_codes; /* tracks entered cyphercon codes */
int *key_tracker; /* tracks 8 keys from quest */
mapping careers; /* tracks careers */

string query_name(void);

/* Save the player */
void save_me(void) {
   if ((living_name != "guest") && (living_name != "who")) {
      unguarded("save_object", "/data/players/" + living_name + ".o");
   }
}

void restore_privs(void) {
   string privs;

   if (user) {
      privs = "game:" + user->_Q_cpriv();
   } else {
      privs = "game:nobody";
   }

   run_as(privs);
}

int gmcp(void) {
  return user->gmcp();
}

mapping gmcp_support(void) {
  return user->gmcp_support();
}

int gmcp_support_type(string lookup) {
  mapping supports;
  supports = user->gmcp_support();
  if (supports[lookup]) {
    return supports[lookup];
  } else {
    return 0;
  }
}

void send_ga(void) {
  user->send_ga();
}

void send_subnegotiation(string package) {
  /* Send IAC SB - TELNET SUBNEGOTIATION */
  user->send_subnegotiation(package);
}

void send_gmcpsubnegotiation(string package) {
  /* Send IAC SB - TELNET SUBNEGOTIATION */
  user->send_subnegotiation(GMCP + package);
}
string gmcp_client(void) {
  return user->gmcp_client();
}
string gmcp_version(void) {
  return user->gmcp_version();
}


/* Restore the player */
void restore_me(void) {
   if (!unguarded("restore_object", "/data/players/" + living_name + ".o")) {
      write("Error while restoring \"/data/players/" + living_name + ".o");
      write("Please notify the administration.");
      return;
   }

   set_id(living_name);

   if (!alias) {
      alias = ([]);
   }

   if (cmd_path) {
      int i, sz;

      /* convert cmd_path */
      for (i = 0, sz = sizeof( cmd_path ); i < sz; i++) {
         if (cmd_path[i] == "/kernel/cmds/admin") { 
            cmd_path[i] = "/sys/cmds/admin";
         } else if (cmd_path[i] == "/cmds/wiz") {
            cmd_path[i] = "/sys/cmds/wiz";
         }
      }
      cmd::set_cmd_path( cmd_path );
      cmd_path = nil;
      call_out( "save_me", 0 );
   }
}

void set_env(string name, mixed value) {
   if (!environment_variables) {
      environment_variables = ([]);
   }
   if (name == "PATH") {
      /* we always require the wiz cmdpath so set remains available 
         for changing the path again */
      if (sizeof(explode(value, ":") & 
         ({ "$PATH", "/sys/cmds/wiz", "/sys/cmds/wiz/" }) ) >= 1) {
         cmd::set_searchpath(value);
      }
   } else {
      environment_variables[name] = value;
   }
   if (living_name) {
      save_me();
   }
}

mixed query_env(string name) {
   if (!environment_variables) {
      environment_variables = ([]);
   }
   if (name == "PATH") {
      return cmd::query_searchpath();
   }
   return environment_variables[name];
}

string *query_env_indices(void) {
   if (!environment_variables) {
      environment_variables = ([]);
   }
   return map_indices(environment_variables) + ({ "PATH" });
}

int query_ansi(void) {
   return ansi;
}

void set_ansi(int state) {
   ansi = state;
   save_me();
}

int query_ga(void) {
  if (!ga) {
    return 0;
  }
  return ga;
}

void set_ga(int state) {
   ga = state;
   save_me();
}

int query_difficulty(void) {
  if (this_player()->query_race() == "fed") {
    return 1;
  } else if (this_player()->query_race() == "goon") {
    return 1;
  } else {
    return 0;
  }
}

int query_lives(void) {
  if (lives > 0) {
    return lives;
  } else {
    return 0;
  }
}

int set_lives(int tmp_lives) {
  lives = tmp_lives;
  save_me();
}

int increment_death(void) {
  int tmp_lives;
  string name;
  name = this_object()->query_name();
  write(name);
  tmp_lives = this_object()->query_lives();
  if (tmp_lives < 1) {
    this_object()->message("%^EXT_215%^2 lives remaining...%^RESET%^");
    this_object()->set_lives(1);
    this_object()->save_me();
    return 1;
  } else if (tmp_lives == 1) {
    this_object()->message("%^EXT_215%^1 life remaining...%^RESET%^");
    this_object()->set_lives(2);
    this_object()->save_me();
  } else if (tmp_lives == 2) {
    this_object()->message("%^EXT_215%^no life remaining...%^RESET%^");
    this_object()->set_lives(3);
    this_object()->save_me();
  } 
  tmp_lives = this_object()->query_lives();
  if (tmp_lives > 2) {
    this_object()->message("Game Over...");
    this_object()->message("Your account has been deleted...");
    this_object()->message("Better luck next time...");
    USER_D->delete_user(this_object()->query_name());
    return 1;
  } else {
    return 1;
  }
}

int re_arm(void) {
  lives = 0;
  save_me();
}

int query_mxp_support() {
  if (this_player()->query_race() == "fed") {
    return 0;
  }
  return user->mxp_support();
}

int query_mxp(void) {
  if (this_player()->query_race() == "fed") {
    return 0;
  }
   return mxp | user->mxp_support();
}

void set_mxp(int state) {
   mxp = state;
}

int *get_woodland_kills(void) {
  return woodland_kills;
}

int *get_key_tracker(void) {
  return key_tracker;
}


int *get_cypher_codes(void) {
  return cypher_codes;
}

void set_woodland_kills(int * flag) {
   woodland_kills = flag;
}

void set_cypher_codes(int * flag) {
   cypher_codes = flag;
}

void set_key_tracker(int * flag) {
   key_tracker = flag;
}

int query_lastpaid(void) {
   return lastpaid;
}

string query_minelocation(void) {
   return minelocation;
}

int query_minestate(void) {
  return minestate;
}

int query_deathproof(void) {
   return deathproof;
}

int cheater(void) {
  if (user->cheat_override() > 0) {
    return 0;
  }
  if (cheater > 0) {
    /* taint the user */
    cheater = 1;
    /* save the user */
    save_me();
    return 1;
  } else {
    return 0;
  }
}

void taint(void) {
  cheater = 1;
  save_me();
}

int query_cheat(void) {
  return user->cheat();
}

int query_lastmined(void) {
   return lastmined;
}

int query_q7_tracker(void) {
   return q7_tracker;
}

void set_lastmined(void) {
   lastmined = time();
   save_me();
}

void set_mined(int mined) {
   lastmined = mined;
   save_me();
}

void set_lastpaid(void) {
   lastpaid = time();
   save_me();
}

void set_minelocation(void) {
   minelocation = this_environment()->file_name();
   save_me();
}

void set_minestate(int state) {
  minestate = state;
  save_me();
}

void set_deathproof(int state) {
  deathproof = state;
  save_me();
}

void set_q7_tracker(int state) {
   q7_tracker = state;
   save_me();
}

void set_career(string career, string rank) {
  if (!careers) {
     careers = ([ ]);
  }
  careers[career] = rank;
  save_me();
}

string get_career_rank(string career) {
   string rank;
   if (careers) {
     rank = careers[career];
   } else {
     rank = "C";
   }
   if (rank) {
     return rank;
   } else {
     return "C";
   }
}

int is_career(string career) {
   if (careers[career]) {
      return 1;
   }

   return 0;
}

void remove_careers(string career) {
   careers[career] = nil;
   save_me();
}

string *query_careers(void) {
   return map_indices(careers);
}


void create(void) {
   con::create();
   bod::create();
   cmd::create();
   history::create();

   channels = ( { "gossip", "announce" } );
   ignored = ( { } );
   title = "$N the newbie";
   long_desc = "";
   set_short("A newbie");
   timestamp = time();
   ansi = 1;
   set_env("cwd", "/");
   autoload = 1;
   save_on_quit = 0;
   hidden = 0;
   debug_commands = 0;
   verbose_errors = 0;
   display_caught = 0;
   living_name = "who";
   custom_colors = ([]);
   key_tracker = (( { 0, 0, 0, 0, 0, 0, 0, 0 } ));
   woodland_kills = (( { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } ));
   level = 1;
}

void setup(void) {
}

string query_title(void) {
   string t, t2;

   t = title;
   if (!query_name()) {
      return "";
   }

   if (!t || t == "") {
      t = "$N the title less";
   }
   t2 = replace_string(t, "$N", capitalize(living_name));
   if (t2 == t) {
      t2 = capitalize(living_name) + " " + t;
   }

   return t2;
}

void set_title(string t) {
   title = t;
   set_short(query_title());
}

string query_title_string(void) {
   return title;
}

void login_player(void) {
   int i, is_new_player;
   string *wizlog, *tmpchannels;
   string race;

   restore_privs();
   set_mxp(0);

   /* If we're a wiz, show the wizlog since last login */
   if (query_user_type(living_name) > 0) {
      wizlog = WIZLOG_D->get_entries(last_login);

      if (wizlog) {
         for (i = 0; i < sizeof(wizlog); i++) {
            if (wizlog[i] == "") {
               write("\n");
            } else {
               write(wizlog[i]);
            }
         }
      }
   }

   is_new_player = !last_login;
   last_login = time();

   if (is_new_player) {
      EVENT_D->event("new_player", living_name);
   } else {
      EVENT_D->event("player_login", living_name);
   }

   /* Set the current working directory */
   if (!query_env("cwd")) {
      set_env("cwd", "/");
   }

   /* Subscribe to default channels */
   if (!channels) {
      channels = ( { } );
   }

   tmpchannels = channels;
   channels = ( { } );

   /* Register with the subscribed channels */
   for (i = 0; i < sizeof(tmpchannels); i++) {
      if (CHANNEL_D->query_channel(tmpchannels[i])) {
         if (!CHANNEL_D->chan_join(tmpchannels[i], this_player())) {
            write("Error joining channel: " + tmpchannels[i] + "\n");
         }
      } else {
         write("Error no such channel: " + tmpchannels[i] + "\n");
         tmpchannels[i] = nil;
      }
   }

   race = query_race();
   set_race(race, is_new_player);
   if (is_new_player) {
      set_hit_skill("combat/unarmed");
   }

   set_short(query_title());
   set_internal_max_weight((15 + query_statbonus("str")) * 100);
   ANSI_D->set_player_translations(custom_colors);

   if (autoload == 1) {
      this_player()->clone_autoload_objects();
   }

}

int query_height(void) {
   if (terminal_height < 8) {
     if (user->naws_support()) {
       return user->naws_height();
     } else {
      return 23;
     }
   } else {
    return terminal_height;
   } 
}

void set_height(int i) {
   if (i < 0 || i == 1) {
      terminal_height = 23;
   }
   else if (i == 0) {
      terminal_height = INT_MAX;
   }
   else if (i < 5) {
      terminal_height = 5;
   }
   else {
      terminal_height = i - 1;
   }
}

int query_width(void) {
   if (terminal_width < 20) {
     if (user->naws_support()) {
       return user->naws_width();
     } else {
      return DEFAULT_WIDTH;
     }
   } else {
    return terminal_width;
   } 
}

int query_naws_width(void) {
  return user->naws_width();
}

void set_width(int i) {
   if (i < 2) {
      terminal_width = DEFAULT_WIDTH;
   }
   else if (i < 8) {
      terminal_width = 8;
   }
   else {
      terminal_width = i;
   }
}

int query_hidden(void) {
   return hidden;
}

void set_hidden(int i) {
   if (i > 0) {
      hidden = 1;
   }
   else {
      hidden = 0;
   }
}

int query_autoload(void) {
   return autoload;
}

void set_autoload(int i) {
   autoload = i;
}

int query_save_on_quit(void) {
   return save_on_quit;
}

void set_save_on_quit(int i) {
   save_on_quit = i;
}

string query_quit_message(void) {
   if (!quit_message) {
      return "$N $vquit.";
   }

   return quit_message;
}

void set_quit_message(string str) {
   quit_message = str;
}

int query_debug_commands(void) {
   return debug_commands;
}

void set_debug_commands(int i) {
   debug_commands = i;
}

int query_verbose_errors(void) {
   return verbose_errors;
}

void set_verbose_errors(int i) {
   verbose_errors = i;
}

int query_display_caught(void) {
   return display_caught;
}

void set_display_caught(int i) {
   display_caught = i;
}

string query_start_room(void) {
   if (!start_room) {
      return STARTING_ROOM;
   }

   return start_room;
}

void set_start_room(string path) {
   start_room = path;
   save_me();
}

string query_death_room(void) {
   if (!death_room) {
    if (start_room == "/domains/core/rooms/city/x40y-90z0.c") {
      return "/domains/core/rooms/city/x-10y-40z0.c";
    } else {
      return STARTING_ROOM;
    }
   }

   return death_room;
}

void set_death_room(string path) {
   death_room = path;
   save_me();
}

string query_prompt(void) {
   if (!prompt) {
      return "%h/%H %b/%B %e/%E>";
   }

   return prompt;
}

void set_prompt(string str) {
   prompt = str;
}

int query_last_login(void) {
   return last_login;
}

void set_last_tell(string who) {
   last_tell = who;
}

string query_last_tell(void) {
   return last_tell;
}

int is_player(void) {
   return 1;
}

void set_user(object usr) {
   user = usr;
}

void set_linkdead(int flag) {
   if (flag == 1) {
      LINKDEAD_D->add_linkdead(this_object());
      EVENT_D->event("player_linkdeath", query_name());
      set_short(query_title() + " [link-dead]");
      linkdead = call_out("do_quit", LINKDEAD_TIMEOUT);
   } else {
      set_short(query_title());
      if (linkdead) {
         remove_call_out(linkdead);
         EVENT_D->event("player_unlinkdeath", query_name());
      }
      linkdead = 0;
   }
}

void set_editing(int flag) {
   if (flag == 1) {
      set_short(query_title() + " [editing]");
   } else {
      set_short(query_title());
   }
}

int query_linkdead(void) {
   return (linkdead > 0);
}

int query_idle(void) {
   return (time() - timestamp);
}

object query_user(void) {
   return user;
}

void set_realname(string str) {
   real_name = str;
}

string query_realname(void) {
   if (!real_name) {
      return "";
   }

   return real_name;
}

void set_email(string str) {
   email_address = str;
}

string query_email(void) {
   if (!email_address) {
      return "";
   }

   return email_address;
}

void set_website(string str) {
   website = str;
}

string query_website(void) {
   if (!website) {
      return "";
   }

   return website;
}

void initialize_cmd_path(void) {
   cmd::set_cmd_path( ({ "/cmds/player/" }) );
}

/* Add a path to the command path */
void add_cmd_path(string path) {
   if (require_priv(owner_file(path))) {
      cmd::add_cmd_path( path );
   } else {
      error("Permission denied.");
   }
}

string *query_path(void) {
   return cmd::query_cmd_path();
}

void add_channel(string chan) {
   if (!channels) {
      channels = ( { } );
   }

   channels -= ( { chan } );
   channels += ( { chan } );
}

void remove_channel(string chan) {
   if (!channels) {
      channels = ( { } );
   }

   channels -= ( { chan } );
}

string *query_channels(void) {
   return channels;
}

void add_ignore(string who) {
   if (!who || who == "") {
      return;
   }

   ignored += ( { lowercase(who) } );
}

void remove_ignore(string who) {
   if (!ignored) {
      ignored = ( { } );
   }

   ignored -= ( { lowercase(who) } );
}

int query_ignored(string who) {
   if (!ignored) {
      ignored = ( { } );
   }

   if (!who || who == "") {
      return 0;
   }

   who = lowercase(who);
   return member_array(who, ignored) >= 0;
}

string *query_ignored_all(void) {
   if (!ignored) {
      ignored = ( { } );
   }

   return ignored;
}

/* Redirect input to another function */
void input_to(string func, varargs mixed arg...) {
   input_to_obj = this_player();
   input_to_func = func;
   input_to_arg = arg;
}

/* Redirect input to another object */
void input_to_object(object ob, string func, varargs mixed arg...) {
   input_to_obj = ob;
   input_to_func = func;
   input_to_arg = arg;
}

/* Send a message to the player */
void message(string str, varargs int chat_flag) {
   if (!this_object()->query_user()) {
      return;
   }
   if (this_object()->is_snooped()) {
      this_object()->do_snoop(str);
   }

   if (chat_flag) {
      this_object()->query_user()->wrap_message(str, 1);
   } else {
      this_object()->query_user()->wrap_message(str);
   }
}

/* Send an almost unmodified message to the player */
void message_orig(string str) {
   if (!query_user()) {
      return;
   }

   if (this_player()->is_snooped()) {
      this_player()->do_snoop(str);
   }
   query_user()->put_message(str);
}

void write_prompt(void) {
  /* delcare all our variables */
   string result, date;
   int hp, maxhp, sp, maxsp, end, maxend, mxp;
   object obj;
   mapping tmp_data;
   string tmp_json, tmp_gmcp;

   tmp_data = ([ ]);


/* setup obj = this_object alias */
   obj = this_object();

   /* query status data */
   hp = obj->query_hp();
   maxhp = obj->query_max_hp();
   sp = obj->query_mana();
   maxsp = obj->query_max_mana();
   end = obj->query_end();
   maxend = obj->query_max_end();
   mxp = obj->query_mxp();

   if (this_player()->gmcp() == 1) {
    tmp_gmcp = "Char.Vitals " + "{";
    tmp_gmcp += "\"hp\":\"" + hp + "\", \"maxhp\":\"" + maxhp + "\", ";
    tmp_gmcp += "\"sp\":\"" + sp + "\", \"maxsp\":\"" + maxsp + "\", ";
    tmp_gmcp += "\"end\":\"" + end + "\", \"maxend\":\"" + maxend + "\"}";
    send_gmcpsubnegotiation(tmp_gmcp);
  }

/* add tags if user is editing */
   if (obj->is_editing()) {
      out("%^GREEN%^edit> %^RESET%^");
      return;
   }

/* find out the users self assigned prompt */
   result = query_prompt();
   if (mxp == 1) {
     result = replace_string(result, ">", "");
   }

/* replacements */
   /* date */
  date = ctime(time());
  result = replace_string(result, "%d", date[4..10] + date[20..23]);
   /* time */
  result = replace_string(result, "%t", ctime(time())[11..18]);
   /* player name */
  result = replace_string(result, "%n", capitalize(living_name));
   /* mud name */
  result = replace_string(result, "%m", MUD_NAME);
   /* no idea */
  result = replace_string(result, "%w", query_env("cwd"));
   /* newline */
  result = replace_string(result, "%_", "\n");

   /* normally for coders, put access check back later */
  if (this_environment()) {
      /* current working directory */
      result = replace_string(result, "%l", this_environment()->file_name());
      if (!this_environment()->query_area()) {
        result = replace_string(result, "%a", "(none)");
      } else {
        result = replace_string(result, "%a",
        /* area name */
        this_environment()->query_area());
      }
  } else {
      result = replace_string(result, "%l", "(no environment)");
      result = replace_string(result, "%a", "(none)");
  }

  if (mxp == 1 ) {
     result = replace_string(result, "%h", "<Hp>" + hp + "</Hp>");
     result = replace_string(result, "%H", "<MaxHp>" + maxhp + "</MaxHp>");
     result = replace_string(result, "%b", "<Mana>" + sp + "</Mana>");
     result = replace_string(result, "%B", "<MaxMana>" + maxsp + "</Mana>");
     result = replace_string(result, "%e", "<End>" + end + "</End>");
     result = replace_string(result, "%E", "<MaxEnd>" + maxend + "</MaxEnd>");
   } else {
     result = replace_string(result, "%h", "" + hp);
     result = replace_string(result, "%H", "" + maxhp);
     result = replace_string(result, "%b", "" + sp);
     result = replace_string(result, "%B", "" + maxsp);
     result = replace_string(result, "%e", "" + end);
     result = replace_string(result, "%E", "" + maxend);
   }

   if (mxp == 1) {
     out("%^MXP_LSM%^<Prompt>" + result + "</Prompt>%^MXP_LLM%^%^RESET%^");
   } else {
     out(result + "%^RESET%^ ");
   }

  send_ga();

}

/* More a set of lines */
void more(string * lines, varargs int docolor) {
   string msg;
   int height;

   if (!lines) {
      return;
   }

   if (docolor && (docolor == 1)) {
      color_more = 1;
   } else {
      color_more = 0;
   }

   if (previous_object() != this_object()) {
      more_caller = previous_object();
   }

   more_line_num = 0;
   more_lines = lines;

   height = query_height() - 1;

   if (sizeof(lines) > height + more_line_num) {

      msg = implode(lines[more_line_num..more_line_num + height], "\n");

      if (docolor) {
         this_object()->query_user()->wrap_message(msg);
      } else {
         out_unmod(msg + "\n");
      }

      out("%^BOLD%^--More--(" + ((more_line_num +
         height) * 100) / sizeof(lines) + "%)%^RESET%^");
      more_line_num += height + 1;
      input_to("more_prompt");
   } else {
      msg = implode(lines[more_line_num..], "\n");

      if (docolor) {
         this_object()->query_user()->wrap_message(msg);
      } else {
         this_object()->query_user()->wrap_message(msg);
      }

      if (more_caller) {
         more_caller->more_done();
         more_caller = nil;
      }
   }
}

/* Write out the more prompt after each page */
void more_prompt(string arg) {
   string msg;
   int height;

   if (!arg || arg == "") {
      arg = " ";
   }
   switch (arg[0]) {
      case 'q':
      case 'Q':
         write_prompt();
         if (more_caller) {
            more_caller->more_done();
            more_caller = nil;
         }
         return;
         break;
   }

   height = query_height() -1;

   if (sizeof(more_lines) > height + more_line_num) {
      msg = implode(more_lines[more_line_num..more_line_num + height],
         "\n");
      if (color_more) {
         this_object()->query_user()->wrap_message(msg);
      } else {
         out_unmod(msg + "\n");
      }

      out("%^BOLD%^--More--(" + ((more_line_num + height) * 100) /
         sizeof(more_lines) + "%)%^RESET%^");
      more_line_num += height + 1;
      input_to("more_prompt");
   } else {
      msg = implode(more_lines[more_line_num..], "\n");

      if (color_more) {
         this_object()->query_user()->wrap_message(msg);
      } else {
         out_unmod(msg + "\n");
      }
      if (more_caller) {
         more_caller->more_done();
         more_caller = nil;
      }
      write_prompt();
   }
}

static void do_look_obj(object obj) {
   int i, flag, mxp;
   string sid;
   object *objs;
   sid = obj->query_id();
   mxp = this_player()->query_mxp();
   this_environment()->event("body_look_at", this_player(), obj);
   this_environment()->tell_room(this_player(), this_player()->query_Name() +
      " looks at the " + obj->query_id() + ".\n");
   write(obj->query_long());
   if (obj->is_closed()) {
      write("It is closed.");
      if (obj->is_locked()) {
         write("It is locked.");
      }
   } else if (obj->is_container()) {
      flag = 0;
      objs = obj->query_inventory();
      if (mxp == 1) {
        out("%^MXP_LSM%^");
      }
      write("It contains:");

      for (i = 0; i < sizeof(objs); i++) {
        if(mxp == 1) {
           write("  <send \"get " + objs[i]->query_id() + " from " + sid + "\">" + objs[i]->query_short() + "</send>\n");
        } else {
           write("  " + objs[i]->query_short() + "\n");
        }
      }
      if (mxp == 1) {
        out("%^MXP_LLM%^");
      }
   }
}

static void do_look_liv(object obj) {
   int i, flag;
   object *objs;

   this_environment()->tell_room(this_player(), this_player()->query_Name() +
      " looks at " + capitalize(obj->query_id()) + ".\n");

   write("%^PLAYER%^" + obj->query_short() + "%^RESET%^\n");

   write(obj->query_long());
   write("A " + obj->query_gender() + " " + obj->query_race() +
      " who is " + obj->query_status() + "\n");

   flag = 0;
   objs = obj->query_inventory();

   if (obj->query_gender() == "male") {
      write(" \nHe is using:\n");
   } else if (obj->query_gender() == "female") {
      write(" \nShe is using:\n");
   } else {
      write(" \nIt is using:\n");
   }

   for (i = 0; i < sizeof(objs); i++) {
      if (objs[i]->is_worn()) {
         write("  " + objs[i]->query_short() + " %^CYAN%^[" +
            objs[i]->query_wear_position() + "]%^RESET%^\n");
         flag = 1;
      } else if (objs[i]->is_wielded()) {
         write("  " + objs[i]->query_short() + " %^CYAN%^[" +
            objs[i]->query_wield_position() + "]%^RESET%^\n");
         flag = 1;
      }
   }
   if (flag == 0) {
      write("  Nothing.");
   }
}



void do_look(object obj) {
   int i, flag;
   object *objs;

   if (this_environment()->is_dark()) {
      if (query_wizard(this_player())) {
         write("This room is dark, however, being a wizard allows " +
            "you to see in the dark.\n");
      } else if (this_player()->query_race_object()->has_darkvision()) {
         write("This room is dark, however, your race allows " +
            "you to see in the dark.\n");
      } else if (this_player()->has_darkvision()) {
      } else {
         write("It is too dark to see.\n");
         return;
      }
   }

   if (obj == this_environment()) {
      this_environment()->event("body_look", this_player());
      if (query_wizard(this_player() ) ) {
         write("%^BOLD%^<\"" + this_environment()->file_name() +
            "\">%^RESET%^");
      }

      write(this_environment()->query_desc());
   } else if (obj->is_living()) {
      do_look_liv(obj);
   } else {
      do_look_obj(obj);
   }
}

void do_quit(void) {
   object sp, *objs;
   string quitcmd, *channelstmp;
   int i;

   sp = this_player();

   set_this_player(this_object());

   if (autoload) {
      this_object()->compose_autoload_string();
   }

   objs = query_inventory() + ( { } );

   if (is_possessing()) {
      command( "possess", nil );
   }

   for (i = 0; i < sizeof(objs); i++) {
      if (objs[i]->is_undroppable() || autoload == 1) {
         objs[i]->destruct();
      } else {
         if (objs[i]->is_worn()) {
            this_player()->do_remove(objs[i]);
            this_player()->targeted_action(objs[i]->query_remove_message(),
               nil, objs[i]);
         }
         if (objs[i]->is_wielded()) {
            this_player()->do_unwield(objs[i]);
            this_player()->targeted_action(objs[i]->query_unwield_message(),
               nil, objs[i]);
         }

         if (objs[i]->move(this_object()->query_environment())) {
            this_object()->targeted_action("$N $vdrop $o.", nil, objs[i]);
         } else {
            objs[i]->destruct();
         }
      }
   }

   if (save_on_quit) {
      object room;

      room = this_player()->query_environment();
      if (room) { 
         start_room = room->file_name();
      }
   }

   TOP_SCORE_D->save(this_player());

   quitcmd = this_player()->query_quit_message();
   this_object()->simple_action(quitcmd);

   channelstmp = channels;
   for (i = 0; i < sizeof(channels); i++) {
      if (CHANNEL_D->query_channel(channels[i])) {
         CHANNEL_D->chan_leave(channels[i], this_object());
      } else {
         channels[i] = nil;
      }
   }
   channels = channelstmp;
   EVENT_D->event("player_logout", living_name);
   LINKDEAD_D->remove_linkdead(this_object());
   quitting = 1;
   set_this_player(sp);
   query_user()->quit();
}

/* Destruct this player */
void destruct(void) {
   move_or_destruct_inventory();
   ::destruct();
}

/* Alias handling */

int is_alias(string cmd) {
   if (!alias) {
      alias = ([]);
   }
   if (alias[cmd]) {
      return 1;
   }
   return 0;
}

string query_alias(string cmd) {
   if (!alias) {
      alias = ([]);
   }

   return alias[cmd];
}

void add_alias(string cmd, string new_alias) {
   if (!alias) {
      alias = ([]);
   }

   alias[cmd] = new_alias;
}

void remove_alias(string cmd) {
   if (!alias) {
      alias = ([]);
   }

   alias[cmd] = nil;
}

mapping query_aliases(void) {
   if (!alias) {
      alias = ([]);
   }

   return alias;
}

/* Guild routines */

void join_guild(string guild) {
   if (!guilds) {
      guilds = ([]);
   }

   guilds[guild] = GUILD_D->query_guild_title(guild);
   add_cmd_path( "/cmds/guild/" + guild );
   save_me();
}

void leave_guild(string guild) {
   if (!guilds) {
      guilds = ([]);
   }

   guilds[guild] = nil;
   remove_cmd_path( "/cmds/guild/" + guild );
   set_title("$N the guildless");
   save_me();
}

int guild_member(string guild) {
   if (!guilds) {
      guilds = ([]);
   }

   if (guilds[guild]) {
      return 1;
   }
   return 0;
}

string *query_guilds(void) {
   string *blah;

   if (guilds) {
      blah = map_indices(guilds);
   }

   return blah;
}

string random_error(void) {
   int randomval;

   randomval = random(7);
   switch (randomval) {
      case 0:
         return "< %^RED%^Status 400%^RESET%^ PC LOAD LETTER.....";
         break;
      case 1:
         return "< %^RED%^Status 401%^RESET%^ I'm sorry dave I can't do that";
         break;
      case 2:
         return "< %^RED%^Status 402%^RESET%^ PEBKAC%^RESET%^";
         break;
      case 3:
         return "< %^RED%^Status 403%^RESET%^ %^GREEN%^help%^RESET%^";
         break;
      case 4:
         return "< %^RED%^Status 404%^RESET%^ You Screwed Up";
         break;
      case 5:
         return "< %^RED%^Status 405%^RESET%^ Unprocessable Entity";
         break;
      case 6:
         return "< %^RED%^Status 406%^GREEN%^ cmds%^RESET%^";
   }
}

/* Process input from the player */
void receive_message(string message) {
   mixed result;
   string func, cmd, arg, *exits;
   int i, flag, is_history;
   object room;

   flag = 0;
   is_history = 0;

   /* Update the timestamp so we're not idle */
   timestamp = time();

   arg = "";

   if (this_player()->is_snooped()) {
      this_player()->do_snoop(message);
   }

   /* Redirect the input somewhere else */
   if (input_to_func != "") {
      func = input_to_func;
      input_to_func = "";
      call_other(input_to_obj, func, message, input_to_arg...);
   } else if (is_editing()) {
      this_player()->edit(message);
   } else {
      string temp;

      /* History */
      if (message == get_history_character()) {
         out(list_history());
         is_history = 1;
         flag = 1;
      } else if (!empty_str(message) && message[0] == get_history_character()[0]) {
         int history_nr;
         if (sscanf(message[1..], "%d", history_nr)) {
            message = get_history(history_nr);
         } else {
            message = get_history(message[1..]);
         }
         is_history = 1;
      }
      if (is_history == 1 && message != get_history_character()) {
         out(message + "\n");
         if (query_command_not_found_in_history(message)) {
            flag = 1;
         }
      }

      /* Expand the command */
      temp = ALIAS_D->expand_alias(message);
      if (temp) {
         message = temp;
      }

      /* Split the input into command and argument */
      if (sscanf(message, "%s %s", cmd, arg) != 2) {
         cmd = message;
      }

      if (is_alias(cmd)) {
         message = ALIAS_D->do_expand(query_alias(cmd), arg);
         if (sscanf(message, "%s %s", cmd, arg) != 2) {
            cmd = message;
         }
      }

      if (cmd != "") {
         if (cmd[0] == '\'') {
            if (arg == "") {
               arg = cmd[1..];
            } else {
               arg = cmd[1..] + " " + arg;
            }
            cmd = "say";
         } else if (cmd[0] == ';') {
            if (arg == "") {
               arg = cmd[1..];
            } else {
               arg = cmd[1..] + " " + arg;
            }
            cmd = "emote";
         }
      }

      /* Substitute 'me' with my name */
      if (arg == "me") {
         arg = this_player()->query_id();
      }

      /* Check for an object command in objects in my inv */
      if (!flag) {
         object player;
         string roomcmd_h;

         player = this_player();
         if (player) {
            object *objs;
            int y, maxy;

            objs = player->query_inventory();
            if (objs) {
               maxy = sizeof(objs);
               for (y = 0; y < maxy; y++) {
                  roomcmd_h = objs[y]->query_action(cmd);

                  if (roomcmd_h) {
                     flag = call_other(objs[y], roomcmd_h, arg);
                  }
               }
            }
         }
      }

      /* Check for an object command in the room */
      if (!flag) {
         object room;
         string objectcmd_h;

         room = this_player()->query_environment();
         if (room) {
            objectcmd_h = room->query_action(cmd);

            if (objectcmd_h) {
               flag = call_other(room, objectcmd_h, arg);
            }
         }
      }

      /* Check for an object command in objects in the room */
      if (!flag) {
         object room;
         string roomcmd_h;

         room = this_player()->query_environment();
         if (room) {
            object *objs;
            int y, maxy;

            objs = room->query_inventory();
            if (objs) {
               maxy = sizeof(objs);
               for (y = 0; y < maxy; y++) {
                  roomcmd_h = objs[y]->query_action(cmd);

                  if (roomcmd_h) {
                     flag = call_other(objs[y], roomcmd_h, arg);
                  }
               }
            }
         }
      }

      /* Check for a room command */
      if (!flag) {
         object room;
         string roomcmd_h;

         room = this_environment();
         if (room) {
            roomcmd_h = room->query_action(cmd);
            if (roomcmd_h) {
               flag = call_other(room, roomcmd_h, arg);
            }
         }
      }

      /* Call command_d to check if it handles this command, returns -1 
         when it doesn't */
      if (!flag) {
         i = command( cmd, arg );
         if ( i >= 0 ) {
            flag = 1;
         }
      }

      if (!flag) {
         /* XXX shouldn't add cmd and arg but have to right now */
         flag = do_game_command(cmd + " " + arg);
      }

      if (!flag) {
         /* Is it a channel? */
         if (CHANNEL_D->query_channel(cmd) == 1) {
            /* Okay, it's a channel. Are we privileged enough to use it? */
            if (CHANNEL_D->query_priv(cmd) + 1 == READ_ONLY ||
               CHANNEL_D->query_priv(cmd) <= query_user_type(living_name)) {

               flag = 1;
               command("chan", cmd + " " + arg);
            }
         }
      }

      if (!flag) {
         /* Is it an exit? */
         exits = this_environment()->query_exit_indices();
         for (i = 0; i < sizeof(exits); i++) {
            if (exits[i] == lowercase(cmd)) {
               command("go", cmd);
               flag = 1;
            }
         }
      }

      if (!flag && cmd != "") {
         write(random_error());
      } else {
         if (is_history == 0) {
            push_history(message);
         }
      }
      if (!quitting && (input_to_func == "") && !is_editing()) {
         write_prompt();
      }
   }
}

void set_custom_color(string name, string * symbols) {
   int i, sz;
   string tmp;

   tmp = "";
   if (!custom_colors) {
      custom_colors = ([]);
   }

   if (!symbols) {
      custom_colors[name] = nil;
      write("Removed color symbol " + name + "\n");
   } else {
      for (i = 0, sz = sizeof(symbols); i < sz; i++) {
         if (strstr("%^", symbols[i]) == -1) {
            symbols[i] = uppercase(symbols[i]);
            if (!ANSI_D->query_any_symbol(symbols[i])) {
               /* Each symbol must resolve to a pre-defined token */
               write("Symbolic color tokens must be composed of only " +
                  "valid base color tokens or pre-existing custom tokens.\n" +
                  "see 'ansi show' for valid tokens");
               return;
            } else {
               switch (ANSI_D->check_recursion(name, symbols[i])) {
                  case 2:
                     write("Loop in symbolic tag " + name + " : " + symbols[i]);
                     return;
                  case 1:
                     write("Too many levels of symbolic tags for " + name);
                     return;
               }
            }
            tmp += "%^" + symbols[i] + "%^";
         } else {
            write("Symbolic color tokens cannot (YET) contain custom tokens\n");
            return;
         }
      }

      custom_colors[name] = tmp;
      out_unmod(name + " is now " + tmp + "\n");
   }

   ANSI_D->set_player_translations(custom_colors);
   save_me();
}

void store_menu(mixed header, mixed * menu, mixed footer, mapping actions) {
   menu_data = ( { header, menu, footer, actions } );
}

mixed *retrieve_menu(void) {
   if (menu_data) {
      return menu_data;
   } else {
      return ( { nil, nil, nil, nil } );
   }
}

int query_muzzle(void) {
   return muzzle;
}

int toggle_muzzle(void) {
   if (muzzle) {
      muzzle = 0;
   } else {
      muzzle = 1;
   }

   return muzzle;
}

int can_carry(object "/std/object" obj) {
   int tmp;

   this_object()->update_internal_weight();
   tmp = internal_weight + obj->query_weight();

   if (tmp < query_internal_max_weight()) {
      return 1;
   }

   return 0;
}

void update_internal_weight(void) {
   object *inv;
   int i, dim, w;

   inv = query_inventory();
   for (i = 0, w = 0, dim = sizeof(inv); i < dim; i++) {
      w += inv[i]->query_weight();
   }

   set_internal_weight(w);
}

