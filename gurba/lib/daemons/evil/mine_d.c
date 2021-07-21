void restore_me(void);
void save_me(void);
#define DATAFILE "/daemons/data/evil/mine_d.o"

mapping callouts;

void create(void) {

   callouts =([ ]);

   if (file_exists(DATAFILE)) {
      restore_me();
   } else {
      /* Create a default list if we do not already have one. */
      save_me();
   }
}

static void restore_me(void) {
   unguarded("restore_object", DATAFILE);

}

static void save_me(void) {
   unguarded("save_object", DATAFILE);
}

void set_callout(string pname, int callout) {
  callouts[pname] = callout;
  save_me();
}

int get_callout(string pname) {
   if (callouts[pname] > 0) {
      return callouts[pname];
   } else {
      return 0;
   }
}

void remove_callout(string pname) {
   callouts[pname] = 0;
   save_me();
}

string *query_locks(void) {
   return map_indices(callouts);
}

