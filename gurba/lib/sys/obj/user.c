/* Thingol, 9/26/2009. Fixed wrap_message() to wrap to the correct length. */
#include <limits.h>
#include <status.h>
#include <ports.h>
#include <telnet.h>

inherit "/sys/lib/runas";
inherit telnet "/sys/lib/telnet";
inherit M_SERIALIZE;

object player;
object ansid;

string user_name;
string newpass;
static int logged_in;
static int data_version;
static int timeout_handle;
private static int auto_admin, auto_wiz;
private int cheat_override;
private int easy_override;
private int cheat;
private int mxp;
private int naws;
private int gmcp;
private int gmcp_ping_timer;
private string gmcp_subnegotiation;
private string discord_username;
private string discord_private;
private string terminal_type;
private int ttype;
private string gmcp_support_string;
private mapping gmcp_support;
private string gmcp_client;
private string gmcp_version;
private int naws_height, naws_width;
object query_player(void);

void create(void) {
   ansid = find_object(ANSI_D);
   if (!ansid) {
      ansid = compile_object(ANSI_D);
   }

   auto_admin = 0;
   auto_wiz = 0;
   user_name = "who";
   data_version = 3;
   run_as("nobody");
}

/* MXP Initialization code */
void mxp_init() {
  /* Enter Permanent Secure Mode to enable MXP */
  out("%^MXP_LSM%^<!-- Elements to support the Automapper -->");
  /* room tags */
  out("<!ELEMENT RName FLAG=\"RoomName\">");
  out("<!ELEMENT RDesc FLAG=\'RoomDesc\'>");
  out("<!ELEMENT RExits  FLAG=\'RoomExit\'>");
  /* exit tags */
  out("<!-- The next element is used to define a room exit link that sends the exit direction to the MUD if the user clicks on it -->");
  out("<!ELEMENT Ex \'<SEND>\'><!ELEMENT Announce \'<FONT COLOR=Cyan>\' OPEN><!ELEMENT Gossip \'<FONT COLOR=Green>\' OPEN>");
  out("<!-- the next elements deal with the MUD prompt -->");
  /* prompt tags */
  out("<!ELEMENT Prompt FLAG=\"Prompt\">");
  out("<!ELEMENT Hp FLAG=\"Set hp\"><!ELEMENT MaxHp FLAG=\"Set maxhp\">");
  out("<!ELEMENT Mana FLAG=\"Set mana\"><!ELEMENT MaxMana FLAG=\"Set maxmana\">");
  out("<!ELEMENT End FLAG=\"Set end\"><!ELEMENT MaxEnd FLAG=\"Set maxend\">");
  out("<!ELEMENT RoomX FLAG=\"Set room_x\"><!ELEMENT RoomY FLAG=\"Set room_y\"><!ELEMENT RoomZ FLAG=\"Set room_Z\">");
  /* click on item tags */
  out("<!EL Itm \'<send \"look &text;|drop &text;|wear &text;|wield &text;|drink &text;|unwield &text;|remove &text;\">\'>");
  out("<!EL Click \'<send \"&text;\">\'><!EL ClickP \'<send \"&text;\" PROMPT>\'>%^MXP_LLM%^");
}

void send_ga(void) {
  /* Send IAC GA */
  telnet::send(IAC + "\xf9");
}

void send_subnegotiation(string package) {
  /* Send IAC SB - TELNET SUBNEGOTIATION */
  telnet::send(IAC + SB + package + IAC + SE);
}


/* TELNET WILL SUPPORT - IAC WILL */
static void telnet_will(int option) {
      /* Enable MXP Escape on IAC WILL MXP */
      /* leave MXP check in to prevent loop */
    if (option == TELOPT_MXP[0] && mxp != 1) {
        telnet::send(IAC + SB + TELOPT_MXP + IAC + SE);
        mxp_init();
        mxp = TRUE;
    /* Enable Negotiate About Window Size - IAC NAWS */
    } else if (option == NAWS[0] && naws !=1) {
        telnet::send(IAC + DO + NAWS + IAC + SE);
        naws = TRUE;
    /* Enable Terminal Type - IAC TTYPE */
    } else if (option == TERMINAL_TYPE[0] && ttype !=1) {
        telnet::send(IAC + SB + "\x18" + "\x01" + IAC + SE);
        naws = TRUE;
    } else {
        ::telnet_will(option);    /* pass on other options to lower layer */
    }
}

/* TELNET DO SUPPORT - IAC DO */
static void telnet_do(int option) {
    /* Enable MXP on IAC DO */
    /* leave MXP check in to prevent loop */
    if (option == TELOPT_MXP[0] && mxp != 1) {
        telnet::send(IAC + SB + TELOPT_MXP + IAC + SE);
        mxp_init();
        mxp = 1;
        return;
    } else if (option == GMCP[0] && gmcp != 1) {
        gmcp = 1;
        return;
    } else {
        ::telnet_do(option);    /* pass on other options to lower layer */
    }
}

static void telnet_dont(int option) {
  ::telnet_dont(option);  /* pass on other options to lower layer */
}


/* GMCP Subnegotiation code */
static void telnet_subnegotiation(string subnegotiation) {
  if (subnegotiation[0] == 31) { /* NAWS */
     if (subnegotiation[1] == '0') { /* ignore leading zero's */
       naws_width = subnegotiation[2];
     } else {
       naws_width = (256 * subnegotiation[1]) + subnegotiation[2];
     }
     if (subnegotiation[3] == '0') { /* ignore leading zero's */
       naws_height = subnegotiation[4];
     } else {
       naws_height = (256 * subnegotiation[3]) + subnegotiation[4];
     }
  } else if (gmcp == 1) {
    if (gmcp_client == "Mudlet" || gmcp_client == "Mushclient" || terminal_type == "mushclient" || terminal_type == "Mudlet") {
      naws_width = 100;
      naws_height = 40;
      naws = 1;
    }
  }

  /* TTYPE NEGOTIATION */
  if (subnegotiation[0] == TERMINAL_TYPE[0]) {
    int sz_subneg;
    string tmp_ttype;
    sz_subneg = strlen(subnegotiation);
    tmp_ttype = subnegotiation[1..strlen(subnegotiation) - 1];
    terminal_type = tmp_ttype;
  }

  /* Start GMCP Subnegotiation */
  if (subnegotiation[0] == 201) { /* Check if negotiation is GMCP */
    string gmcp, *gmcp_explode, gmcp_package;
    string gmcp_pkg_string;
    mapping json_decoded;
    int sz_gmcp, i, sz_gmcp_explode;

    /* strip gmcp character from subnegotiation */
    gmcp_explode = explode(subnegotiation, "");
    sz_gmcp = sizeof(gmcp_explode);
    gmcp = "";
    for (i = 1; i < sz_gmcp; i++) {
      gmcp += gmcp_explode[i];
    }
    gmcp_explode = explode(gmcp, " ");

    /* get package name */
    gmcp_package = gmcp_explode[0];

    /* get gmcp package substring */
    sz_gmcp_explode = sizeof(gmcp_explode);
    gmcp_pkg_string = "";

    for (i = 1; i < sz_gmcp_explode; i++) {
      gmcp_pkg_string += gmcp_explode[i];
      gmcp_pkg_string += " ";
    }

    if (gmcp_package == "External.cheat.ariana.heal") {
      player->set_hp(player->query_max_hp());
      player->set_sp(player->query_max_sp());
      player->set_end(player->query_max_end());
      player->message("GMCP AUTH SEQ SUCCESS");
    }

    if (gmcp_package == "External.cheat.ariana.rearm") {
      player->message("GMCP AUTH SEQ SUCCESS");
      player->re_arm();
      return;
    }

    if (gmcp_package == "External.cheat.ariana.deathproof") {
      player->message("GMCP AUTH SEQ SUCCESS");
      player->set_deathproof(1);
      return;
    }
    
    if (gmcp_package == "Core.Hello") { /* process Core.Hello */
      string rc;
      string tmp_gmcp_json;
      string junk1, junk2, junk3, junk4;
      tmp_gmcp_json = "Client.GUI {";
      tmp_gmcp_json += "\"version\": \"4\", ";
      tmp_gmcp_json += "\"url\": \"https://mog.ninja/defcon.mpackage\"";
      tmp_gmcp_json += "}";
      telnet::send(IAC + SB + GMCP + tmp_gmcp_json + IAC + SE);
      /* begin evilmogs janky json parser */
      /* eval string hello, str1, str2, str3, str4; hello = this_player()->gmcp_core_hello(); write(hello); sscanf(hello, "{ %s: %s, %s: %s}", str1, str2, str3, str4); write(explode(str2, "\"")[0]);*/
      sscanf(gmcp_pkg_string, "{ %s: %s, %s: %s}", junk1, junk2, junk3, junk4);
      gmcp_client= explode(junk2, "\"")[0];
      gmcp_version = explode(junk4, "\"")[0];
      return;
    }

    if (gmcp_package == "Core.Supports.Set" || gmcp_package == "Core.Supports.Add") { /* process Core.Supports.Set */
      string *temp_expanded;
      string tmp_gmcp_json;
      int i, sz_array;
      gmcp_support_string = gmcp_pkg_string;
      /* explode the string on " so that we can get the supported GMCP out */
      temp_expanded = explode(gmcp_support_string, "\"");
      sz_array = sizeof(temp_expanded);
      if(!gmcp_support || gmcp_package == "Core.Supports.Set") {
        gmcp_support = ([ ]);
      }
      
      /* go to every other item skipping the junk between */
      for (i = 1; i < sz_array; i = i + 2) {
        string part1;
        int part2;
        sscanf(temp_expanded[i], "%s %d", part1, part2);
        if (part2 == 1) {
          gmcp_support[part1] = part2;
        }   
      }
      return;
    }
 
    /* Process Ping Reply */
    if (gmcp_package == "Core.Ping") { /* process Core.Ping */
      int cur_old_ping, cur_new_ping, cur_diff_ping;
      /* time is a digit, stored for later */
      cur_new_ping = time();
      if (!gmcp_ping_timer) {
        gmcp_ping_timer = 0;
      }
      cur_old_ping = gmcp_ping_timer;
      cur_diff_ping = cur_new_ping - cur_old_ping;
      /* standoff to prevent ping storm */
      if (cur_diff_ping > 5) {
        telnet::send(IAC + SB + GMCP + "Core.Ping");
      }
      /* save new time */
      gmcp_ping_timer = cur_new_ping;
      return;
    }

    /* Discord Reply */
    if (gmcp_package == "External.Discord.Hello") {
      string applicationid;
      string discord_invite;
      string gmcp_json_encoded;
      discord_invite = "https://discord.gg/defcon";
      applicationid = "728035108967153795";
      gmcp_json_encoded = "External.Discord.Info { \"inviteurl\": \"" + discord_invite + "\", \"applicationid\": \"" + applicationid + "\" }";
      telnet::send(IAC + SB + GMCP + gmcp_json_encoded + IAC + SE);
      gmcp_json_encoded = "External.Discord.Status { \"game\": \"DEFCON MUD\", \"starttime\": " + time() + " }";
      telnet::send(IAC + SB + GMCP + gmcp_json_encoded + IAC + SE);
      return;
    }
  }

}

/* code to return support values */

/* MXP Support 1 = active */
int mxp_support(void) {
    return mxp;
}

/* GMCP Support 1 = active */
int gmcp(void) {
    return gmcp;
}

mapping gmcp_support(void) {
  if (gmcp == 1) {
    return gmcp_support;
  } else {
    return ([ ]);
  }
}

/* Retrieve Client negotiated by GMCP */
string gmcp_client(void) {
    return gmcp_client;
}

/* Retrieve Version negotiated by GMCP */
string gmcp_version(void) {
    return gmcp_version;
}

/* get last gmcp subnegotiation */
string gmcp_subnegotiation(void) {
    return gmcp_subnegotiation;
}

/* get gmcp support string */
/* this needs to go into an array */
string gmcp_support_string(void) {
  return gmcp_support_string;
}

/* terminal type */
/* XXX TODO */
string terminal_type(void) {
    return terminal_type;
}

/* does client support NAWS */
int naws_support(void) {
    return naws;
}

/* terminal height NAWS */
int naws_height(void) {
  if (naws && (naws_height < 8)) {
    return 23;
  } else {
    return  naws_height;
  }
}

/* terminal width NAWS */
int naws_width(void) {
  if (terminal_type == "Mudlet" || terminal_type == "mushclient") {
    return 100;
  }
  if (naws && (naws_width < 20)) {
    return DEFAULT_WIDTH;
  } else {
    return  naws_width;
  }
}

/* code on connection open */
void _open(mixed * tls) {
   if (SITEBAN_D->is_banned(query_ip_number(this_object()))) {
      /* site is banned */
      LOG_D->write_log("logins", ctime(time()) + "\t" + 
         query_ip_number(this_object()) + "\t" + "Banned Site\n");
      send_message("\nYour site is under an access restriction.\n" +
         "Please email " + ADMIN_EMAIL + " about access from your site.\n");
      destruct_object(this_object());
   }
   telnet::open();
   telnet::send(IAC + DO + TERMINAL_TYPE);
   telnet::send(IAC + WILL + GMCP);
   telnet::send(IAC + WILL + TELOPT_MXP);
   mxp = FALSE;
   send_message("Welcome to " + MUD_NAME + ".\n");
   send_message("Running " + LIB_NAME + " " + LIB_VERSION + " on " +
      status()[ST_VERSION] + ".\n");
   send_message("\x1b[7z\n");
   send_message(TELNET_D->query_banner());
   send_message("\nEnter your name ('quit'): ");
   send_message(1);

   timeout_handle = call_out("login_timeout", 120);
   player = clone_object(PLAYER_OB);
   player->set_user(this_object());
   player->initialize_cmd_path();
   player->initialize_alias();
   player->set_long("A boring player without a description.");
   LOG_D->write_log("logins", ctime(time()) + "\t" + 
      query_ip_number(this_object()) + "\t" + "opening connection\n");
   player->input_to_object(this_object(), "input_name");
}

void open(void) {
   _open(allocate(DRIVER->query_tls_size()));
}

static void _close(mixed * tls, int ld) {
   string ip;

   ip = query_ip_number(this_object());
   if (!ip) {
      ip = "<NO IP>";
   }
   if (ld == 0) {
      player->set_linkdead(1);
      LOG_D->write_log("logins", ctime(time()) + "\t" + ip +
         "\t\t" + this_object()->query_name() + " disconnects\n");
   } else {
      if (player) {
         destruct_object(player);
      }
   }
}

void close(int ld) {
   _close(allocate(DRIVER->query_tls_size()), ld);
}

void login_timeout(void) {
   send_message("\nTimeout.\n");
   destruct_object(player);
   destruct_object(this_object());
}

void quit(void) {
   string str;

   player->save_me();
   LAST_D->add_entry(user_name, 0);
   USER_D->user_offline(user_name, this_object());
   if (query_ip_number(this_object())) {
      LOG_D->write_log("logins", ctime(time()) + "\t" + 
         query_ip_number(this_object()) +
         "\t" + this_object()->query_name() + " quits\n");
   } else {
      LOG_D->write_log("logins", ctime(time()) + "\t" +
         "\t\t" + this_object()->query_name() + " LD quits\n");
   }

   player->destruct();
   destruct_object(this_object());
}

void put_original(string str) {
   if (!str || str == "") {
      return;
   }
   send_message(str);
}

void put_message(string str) {
  string msg;

   if (!str || str == "") {
      return;
   }
   if (query_player()->query_ansi()) {
     msg = ansid->parse_colors(str);
  } else {
    msg = ansid->strip_colors(str);
  }
  send_message(msg);
}

void wrap_message(string str, varargs int chat_flag) {
   string msg, *words, *lines;
   int width, i, j, sz;

   if (!str || str == "") {
      return;
   }

   width = -1;
   /* Get the width from the player */
   if (player) {
      catch(width = player->query_width());
   }

   rlimits(MAX_DEPTH; MAX_TICKS) {
      /* Split the string into lines */
      lines = explode(str, "\n");

      /* Parse each line */
      for (j = 0; j < sizeof(lines); j++) {
         str = lines[j];
         msg = str;
         if (strlen(ansid->strip_colors(str)) > width) {
            int adding;
            string word_todo;

            sz = 0;
            words = explode(str, " ");
            msg = "";

            for (i = 0; i < sizeof(words); i++) {
               word_todo = nil;
               if (strlen(words[i]) > 4 && (strstr(words[i], "%^") != -1)) {
                  word_todo = ansid->strip_colors(words[i]);
               }
               /* word_todo is the word stripped from ansi codes */
               if (!word_todo) {
                  word_todo = words[i];
               }

               if (sz + strlen(word_todo) + adding > width) {
                  msg += "\n";

                  if (chat_flag) {
                     msg += "  ";
                  }

                  /* add length of word without ansi codes */
                  sz = strlen(word_todo) + 2;

                  /* add word with ansi codes */
                  msg += words[i];
               } else {
                  if (adding) {
                     msg += " " + words[i];
                  } else {
                     msg += words[i];
                  }
                  sz += strlen(word_todo) + adding;
               }
               /* determine how many spaces will be added next run */
               if (sz == 0) {
                  adding = 0;
               } else {
                  adding = 1;
               }
            }
         }
         if (query_player()->query_ansi()) {
            msg = ansid->parse_colors(msg);
         } else {
            msg = ansid->strip_colors(msg);
         }

         send_message(msg + "\n");
      }
   }
}

static void _receive_message(string message) {
   rlimits(MAX_DEPTH; MAX_TICKS) {
      if (player->query_possessing()) {
         set_this_player(player->query_possessing());
      } else {
         set_this_player(player);
      }

      player->receive_message(message);
   }
}

void receive_message(string message) {
   telnet::receive(allocate(DRIVER->query_tls_size()), message);
}

/* query USER_D for our privs and setup privileges accordingly */
void restore_privs(void) {
   string privs;

   privs = "";

   if (query_admin(user_name)) {
      privs += "system:";
   }

   if (query_wizard(user_name)) {
      int i, sz;
      string *dn;

      privs += "wizard:";
      dn = DOMAIN_D->query_domains();

      sz = sizeof(dn);
      for (i = 0; i < sz; i++) {
         if (DOMAIN_D->query_domain_member(dn[i], user_name)) {
            privs += dn[i] + ":";
         }
      }
   }

   privs += user_name;

   run_as(privs);
   if (player) {
      player->restore_privs();
   }
}

static void login_user(void) {
   object usr, tmp_player;
   int i, flag, done;
   string start;

   restore_privs();

   send_message(1);

   flag = 0;

   usr = USER_D->find_user(user_name);

   if (usr) {
      send_message("Already logged in.\n");
      flag = 1;
      if (usr->query_player()->query_linkdead() == 1) {
         send_message("Reconnecting to linkdead player.\n");
         tmp_player = usr->query_player();
         usr->set_player(player);
         player = tmp_player;
         set_this_player(player);
         LINKDEAD_D->remove_linkdead(player);
         usr->quit();
         LOG_D->write_log("logins",
            ctime(time()) + "\t" + query_ip_number(this_object()) + "\t" +
            this_object()->query_name() + " reconnects\n");
         player->set_linkdead(0);
         player->set_user(this_object());
         USER_D->user_online(user_name, this_object());
         logged_in = 1;
         player->write_prompt();
         remove_call_out(timeout_handle);
      } else {
         send_message("Reconnect to the other copy? (y/n) : ");
         player->input_to_object(this_object(), "handle_reconnect");
      }
   } else {
      player->set_name(user_name);
      USER_D->user_online(user_name, this_object());
      logged_in = 1;
      player->set_short(capitalize(user_name) + player->query_title());
      send_message("\n\n");
      send_message(TELNET_D->query_motd());
      player->login_player();

      start = player->query_start_room();
      done = 0;
      if (start) {
         done = player->move(start);
         if (!done) {
            send_message("Invalid start room.\n");
         }
      }
      if (!done) {
         done = player->move(STARTING_ROOM);
      }
      if (!done) {
         player->move(VOID);
      }

      player->simple_action("$N $vlog in.\n");
      player->do_look(player->query_environment());
      player->write_prompt();
      remove_call_out(timeout_handle);
      LAST_D->add_entry(user_name, 1);

      LOG_D->write_log("logins", ctime(time()) + "\t" +
         query_ip_number(this_object()) + "\t" +
         this_object()->query_name() + " connects\n");
   }
}

void handle_reconnect(string str) {
   if (!str || str == "") {
      send_message("Please enter y or n : ");
      player->input_to_object(this_object(), "handle_reconnect");
   } else if (lowercase(str) == "y") {
      object usr, tmp_player;
      int flag, i;

      usr = USER_D->find_user(user_name);
      if (usr) {
         flag = 1;
         tmp_player = usr->query_player();
         usr->set_player(player);
         player->set_user(usr);
         player = tmp_player;
         player->set_user(this_object());
         usr->quit();

         LOG_D->write_log("logins", ctime(time()) + "\t" +
           query_ip_number(this_object()) +
           "\t" + this_object()->query_name() + " reconnects\n");

         player->set_linkdead(0);
         send_message("Other copy kicked.\n");
         USER_D->user_online(user_name, this_object());
         logged_in = 1;
         player->write_prompt();
         remove_call_out(timeout_handle);
      }
   } else if (str == "n") {
      send_message("So long then.\n");
      remove_call_out(timeout_handle);
      player->destruct();
      destruct_object(this_object());
   } else {
      send_message("Please enter y or n : ");
      player->input_to_object(this_object(), "handle_reconnect");
   }
}

string query_name(void) {
   return user_name;
}

/* The MSSP specification can be found here: 
   http://tintin.sourceforge.net/mssp/
*/
void mssp_reply(void) {
   /* Change these values in /include/mssp.h */

   send_message("\r\nMSSP-REPLY-START\r\n");

   /* These are Required */
   send_message("NAME\t" + IMUD_NAME + "\r\n"); /* Name of the MUD */
   /* Current number of logged in players */
   send_message("PLAYERS\t" + sizeof(players()) + "\r\n");
   /* Unix time value of the startup time of the MUD */
   send_message("UPTIME\t" + status()[ST_STARTTIME] + "\r\n");

   /* Generic */
   send_message("PORT\t" + LOGIN_PORT + "\r\n");
   send_message("CODEBASE\t" + LIB_NAME + LIB_VERSION + "/" + 
      status()[ST_VERSION] + "\r\n");
   send_message("CONTACT\t" + ADMIN_EMAIL + "\r\n");
   #ifdef WEBSITE
   send_message("WEBSITE\t" + WEBSITE + "\r\n");
   #endif

   /* Categorization */
   send_message("FAMILY\t" + MSSP_FAMILY + "\r\n");
   send_message("STATUS\t" + MSSP_STATUS + "\r\n");
   send_message("INTERMUD\t" + MSSP_INTERMUD + "\r\n");

   /* Protocols */
   send_message("ANSI\t" + MSSP_ANSI + "\r\n");
   send_message("MCCP\t" + MSSP_MCCP + "\r\n");

   /* Commercial */
   send_message("PAY TO PLAY\t" + MSSP_PAY_TO_PLAY + "\r\n");
   send_message("PAY FOR PERKS\t" + MSSP_PAY_FOR_PERKS + "\r\n");

   send_message("MSSP-REPLY-END\r\n");
}

void login_who(void) {
   string *out;
   int i, max;

   out = USER_D->list_players(0);

   max = sizeof(out);
   for (i = 0; i < max; i++) {
      write(out[i]);
   }
}

void write_races(void) {
   int i;
   string line, *races;

   send_message("\n");

   races = RACE_D->query_races();
   for (i = 0; i < sizeof(races); i++) {
      line = capitalize(races[i]) + "              ";
      line = line[..10];
      line += " - " + RACE_D->query_race_short(races[i]) + "\n";
      send_message(line);
   }
   send_message("\n");
}

void input_name(string str) {
   string usr;
   int i;

   if (str == "MSSP-REQUEST") {
      mssp_reply();

      str = "";            /* force login fail */
   }

   if (lowercase(str) == "quit") {
      write("Goodbye!!!\n");
      destruct_object(player);
      destruct_object(this_object());
      return;
   } else if (lowercase(str) == "who") {
      player->set_name("who");
      login_who();
      str = "";
   } else if (lowercase(str) == "guest") {
      write("Goodbye!!!\n");
      destruct_object(player);
      destruct_object(this_object());
      return;
   }

   if (!str || str == "") {
      send_message("\r\nPlease enter your name : ");
      player->input_to_object(this_object(), "input_name");
   } else {
      str = lowercase(str);

      if (strlen(str) > 16) {
         send_message("Name too long.\n");
         input_name("");
         return;
      }
      if (!USER_D->valid_player_name(str)) {
         send_message("A name must start with a letter, and can contain " +
            "letters and numbers.\n");
         input_name("");
         return;
      }

      user_name = str;
      if (BANISH_D->is_banished(user_name)) {
         /* user_name is a banished name */
         LOG_D->write_log("logins", ctime(time()) + "\t" +
            query_ip_number(this_object()) +
            "\t" + query_name() + " <- banished name\n");
         send_message("\nThe name '" + user_name +
            "' is reserved and not available for use.\n");
         destruct_object(player);
         destruct_object(this_object());
         return;
      }
      if (USER_D->player_exists(str)) {
         /* Player exists */
         player->set_name(user_name);
         player->restore_me();
         send_message("Enter your password: ");
         send_message(0);
         player->input_to_object(this_object(), "input_old_passwd");
      } else {
         player->set_name(user_name);
         if (SITEBAN_D->is_newbanned(query_ip_number(this_object()))) {
            /* site is new character banned */
            LOG_D->write_log("logins", ctime(time()) + "\t" +
               query_ip_number(this_object()) +
               "\t" + query_name() + " <- Newbanned site\n");
            send_message("\nThis site is under development and not yet open " +
               "to players.\nPlease email " + ADMIN_EMAIL +
               " about future access from your site.\n");
            destruct_object(player);
            destruct_object(this_object());
            return;
         }

         send_message("Ah. New player.\n");
         send_message("Is '" + user_name + "' correct (y/n)? : ");
         player->input_to_object(this_object(), "input_correct_name");
      }
   }
}

void input_correct_name(string str) {
   if (!str || str == "") {
      send_message("Please enter 'y' or 'n' : ");
      send_message("Is '" + user_name + "' correct (y/n)? : ");
      player->input_to_object(this_object(), "input_correct_name");
   }

   if (lowercase(str) == "y" || lowercase(str) == "yes") {
      send_message("Enter your password: ");
      send_message(0);
      player->input_to_object(this_object(), "input_new_passwd");
   } else {
      send_message("Enter your name : ");
      send_message(1);
      player->input_to_object(this_object(), "input_name");
   }
}

void input_old_passwd(string str) {
   if (!str || str == "") {
      send_message("\nPlease enter your password: ");
      send_message(0);
      player->input_to_object(this_object(), "input_old_passwd");
   }
   if (USER_D->login(user_name, str)) {
      login_user();
   } else {
      send_message("\nPasswords don't match!\n");
      destruct_object(player);
      destruct_object(this_object());
   }
}

void change_passwd(string str) {
   string passwd2;

   send_message("\nOld password: ");
   send_message(0);
   player->input_to_object(this_object(), "change_passwd2");
}

void change_passwd2(string str) {
   if (!str || str == "") { 
      send_message("\nNo password, aborting.\n");
      send_message(1);
      return;
   }

   if (!USER_D->login(user_name, str)) {
      send_message("\nInvalid password, aborting.\n");
      send_message(1);
      return;
   }

   newpass = str;
   send_message("\nNew, password: ");
   send_message(0);
   player->input_to_object(this_object(), "change_passwd3");
}

void change_passwd3(string str) {
   if (!str || str == "") { 
      send_message("\nNo password, aborting.\n");
      send_message(1);
      return;
   }

   newpass = str;
   send_message("\nAgain, new password: ");
   send_message(0);
   player->input_to_object(this_object(), "change_passwd4");
}

void change_passwd4(string str) {
   send_message(1);

   if (!str || str == "") { 
      send_message("\nNo password, aborting.\n");
      return;
   }

   if (newpass != str) {
      send_message("\nPasswords do not match.\n");
      return;
   } else {
      LOG_D->write_log("change_passwd", ctime(time()) + "\t" +
         query_ip_number(this_object()) + "\t" + query_name() + "\n");

      USER_D->set_password(this_player()->query_name(), str);
      send_message("\nPassword successfully changed.\n");
   }
}

void input_new_passwd(string str) {
   if (!str || str == "") {
      send_message("\nPlease enter your password: ");
      send_message(0);
      player->input_to_object(this_object(), "input_new_passwd");
   } else {
      LOG_D->write_log("new_players", ctime(time()) + "\t" +
         query_ip_number(this_object()) + "\t" + query_name() + "\n");
      USER_D->new_user(user_name, str);
      send_message("\nEnter password again: ");
      send_message(0);
      player->input_to_object(this_object(), "input_check_passwd");
   }
}

void input_check_passwd(string str) {
   if (!str || str == "") {
      send_message("\nPlease enter the password again: ");
      send_message(0);
      player->input_to_object(this_object(), "input_check_passwd");
   } else {
      if (USER_D->login(user_name, str)) {
         send_message("\nPlease enter your gender (male/female/other) : ");
         player->input_to_object(this_object(), "input_get_gender");
      } else {
         send_message("\nThe passwords don't match.\n");
         send_message("Goodbye!!!\n");
         USER_D->delete_user(user_name);
         destruct_object(player);
         destruct_object(this_object());
      }
   }
}


void input_get_gender(string str) {
   if (!str || str == "") {
      send_message("Please enter your player gender (male/female/neuter/other):");
      player->input_to_object(this_object(), "input_get_gender");
      return;
   }

   str = lowercase(str);
   if (str == "m" || str == "male") {
      player->set_gender("male");
   } else if (str == "f" || str == "female") {
      player->set_gender("female");
   } else if (str == "n" || str == "neuter") {
      player->set_gender("neuter");
   } else if (str == "o" || str == "other") {
      player->set_gender("other");
   } else if (str == "quit") {
      write("Goodbye!!!\n");
      destruct_object(player);
      destruct_object(this_object());
      return;
   } else {
      send_message("Please use 'male', 'female' or 'other'.\n");
      send_message("Please enter your gender (male/female/other) : ");
      player->input_to_object(this_object(), "input_get_gender");
      return;
   }
   write_races();
   send_message("Please choose one of the races, or type 'info <race>' : ");
   player->input_to_object(this_object(), "input_get_race");
}

void input_get_race(string str) {
   if (!str || str == "") {
      write_races();
      send_message("Please choose one of the races, or type 'info <race>' : ");
      player->input_to_object(this_object(), "input_get_race");
      return;
   }
   str = lowercase(str);

   if (str == "quit") {
      write("Goodbye!!!\n");
      destruct_object(player);
      destruct_object(this_object());
      return;
   }

   if ( (strlen(str) > 5) && (str[0..3] == "info") ) {
      string r;

      r = str[5..( strlen(str) - 1)];
      if (RACE_D->is_race( r ) ) {
         send_message( RACE_D->query_race_long(r) + "\n\n" +
            "Please choose one of the races, or type 'info <race>' : ");
         player->input_to_object(this_object(), "input_get_race");
         return;
      }
   }

   if (!RACE_D->is_race(str)) {
      send_message("Please choose one of the races, or type 'info <race>' : ");
      player->input_to_object(this_object(), "input_get_race");
      return;
   }

   player->set_race(str, 1);

   player->set_hp(player->query_max_hp());
   player->set_mana(player->query_max_mana());
   player->set_end(player->query_max_end());
   player->save_me();
   login_user();
}

void set_player(object p) {
   player = p;
}

object query_player(void) {
   return player;
}

void set_auto_admin(int flag) {
   if (require_priv("system") ) {
      auto_admin = flag;
   }
}

int query_auto_admin() {
      return auto_admin;
}

void set_auto_wiz(int flag) {
   if (require_priv("system") ) {
      auto_wiz = flag;
   }
}

int query_auto_wiz() {
   return auto_wiz;
}

int cheat() {
  if(!cheat || cheat == 0) {
    return 0;
  } else {
    return 1;
  }
}

int cheat_override() {
  if(!cheat_override || cheat_override < 1) {
    return 0;
  } else {
    return cheat_override;
  }
}

int easy_override() {
  if(!easy_override || easy_override < 1) {
    return 0;
  } else {
    return easy_override;
  }
}


static void _receive_error(mixed * tls, string err) {
   console_msg("Network error in user object: " + object_name(this_object()) +
      " : " + err + "\n");
}

void receive_error(string err) {
   _receive_error(allocate(DRIVER->query_tls_size()), err);
}

static void upgraded(void) {
   ansid = find_object(ANSI_D);
   if (data_version) {
      return;
   }
   if (query_player()) {
      logged_in = data_version = 1;
   }
}

int online(void) {
   return logged_in;
}
