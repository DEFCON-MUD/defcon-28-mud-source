void restore_me(void);
void save_me(void);
#define DATAFILE "/daemons/data/evil/color_d.o"

mapping shorts;
mapping longs;
mapping exits;
mapping exitdirs;

void create(void) {

   shorts =([ ]);
   longs = ([ ]);
   exits = ([ ]);
   exitdirs = ([ ]);


   if (file_exists(DATAFILE)) {
      restore_me();
   } else {
     shorts =([ ]);
     longs = ([ ]);
     exits = ([ ]);
     exitdirs = ([ ]);
      /* Create a default list if we do not already have one. */
      /* COLORS */
    save_me();
   }
}

static void restore_me(void) {
   unguarded("restore_object", DATAFILE);

}

static void save_me(void) {
   unguarded("save_object", DATAFILE);
}

void set_short(string room, string str) {
  shorts[room] = str;
  save_me();
}

string query_short(string room) {
   string short;
   short = this_environment()->property("short_color");
   if (shorts[room]) {
      return shorts[room];
   } else if (short) {
      return short;
   } else {
     return "GREEN";
   }
}

int is_short(string room) {
   if (shorts[room]) {
      return 1;
   }

   return 0;
}

void remove_short(string room) {
   shorts[room] = nil;
   save_me();
}

string *query_shorts(void) {
   return map_indices(shorts);
}

void set_long(string room, string str) {
  longs[room] = str;
  save_me();
}

string query_long(string room) {
   string long;
   long = this_environment()->property("long_color");
   if (longs[room]) {
      return longs[room];
   } else if(long) {
      return long;
   } else {
     return "WHITE";
   }
}

int is_long(string room) {
   if (longs[room]) {
      return 1;
   }

   return 0;
}

void remove_long(string room) {
   longs[room] = nil;
   save_me();
}

string *query_longs(void) {
   return map_indices(longs);
}

void set_exit(string room, string str) {
  exits[room] = str;
  save_me();
}

string query_exit(string room) {
   string exit_color;
   exit_color = this_environment()->property("exit_color");
   if (exits[room]) {
      return exits[room];
   } else if (exit_color) {
      return exit_color;
   } else {
     return "HWHITE";
   }
}

int is_exit(string room) {
   if (exits[room]) {
      return 1;
   }

   return 0;
}

void remove_exit(string room) {
   exits[room] = nil;
   save_me();
}

string *query_exits(void) {
   return map_indices(exits);
}

void set_exitdir(string room, string str) {
  exitdirs[room] = str;
  save_me();
}

string query_exitdir(string room) {
   string exit_color;
   exit_color = this_environment()->property("exit_color2");
   if (exitdirs[room]) {
      return exitdirs[room];
   } else if (exit_color) {
      return exit_color;
   } else {
     return "WHITE";
   }
}

int is_exitdir(string room) {
   if (exitdirs[room]) {
      return 1;
   }

   return 0;
}

void remove_exitdir(string room) {
   exitdirs[room] = nil;
   save_me();
}

string *query_exitdirs(void) {
   return map_indices(exitdirs);
}
