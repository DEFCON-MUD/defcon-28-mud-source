void restore_me(void);
void save_me(void);
#define DATAFILE "/daemons/data/evil/cheat_d.o"

mapping cheats;

void create(void) {

   cheats =([ ]);


   if (file_exists(DATAFILE)) {
      restore_me();
   } else {
      /* Create a default list if we do not already have one. */
      /* STOCKS */
      cheats["DEATHPROOF"] = "uw6j79rexfi3yc48q9";
      cheats["SWORD"] = "mjyph73pueqpyt4mqs";
      cheats["S1000"] = "ukbg25p6q4wdgf5anq";
      cheats["LVL5"] = "793jr9w4unkz7evq8m";
      cheats["LVL10"] = "edktazefkz568r6q2x";
      cheats["LVL15"] = "2udsbqnm9thrspurf9";
      cheats["LVL20"] = "r9cpfdajkcihjx7vf9";
      save_me();
   }
}

static void restore_me(void) {
   unguarded("restore_object", DATAFILE);

}

static void save_me(void) {
   unguarded("save_object", DATAFILE);
}

void set_cheat(string cheat, string flag) {
  cheats[cheat] = flag;
  save_me();
}

string query_cheat(string cheat) {
   string flag;
   flag = cheats[cheat];
   return flag;
}

int is_cheat(string cheat) {
   if (cheats[cheat]) {
      return 1;
   }

   return 0;
}

void remove_cheat(string cheat) {
   cheats[cheat] = nil;
   save_me();
}

string *query_cheats(void) {
   return map_indices(cheats);
}

