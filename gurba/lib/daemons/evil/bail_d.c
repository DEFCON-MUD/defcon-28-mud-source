void restore_me(void);
void save_me(void);
#define DATAFILE "/daemons/data/evil/bail_d.o"

mapping bails;

void create(void) {

   bails =([ ]);

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

void set_bail(string player, int amount) {
  bails[player] = amount;
  save_me();
}

int get_bail(string player) {
   if (bails[player] == 0 || (bails[player] == nil)) {
      return 0;
   } else {
      return bails[player];
   }

   return 0;
}

int is_free(string player) {
   if (bails[player] == 0 || bails[player] == nil) {
      return 1;
   } else if (bails[player]) {
     return 0;
   }
   return 0;
}

void remove_bail(string player) {
   bails[player] = nil;
   save_me();
}

string *query_bails(void) {
   return map_indices(bails);
}

