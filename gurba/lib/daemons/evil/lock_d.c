void restore_me(void);
void save_me(void);
#define DATAFILE "/daemons/data/evil/lock_d.o"

mapping locks;

void create(void) {

   locks =([ ]);

   if (file_exists(DATAFILE)) {
      restore_me();
   } else {
      /* Create a default list if we do not already have one. */
      locks["/domains/core/rooms/east/x230y-50z0.c"] = 1;
      locks["/domains/core/rooms/east/x240y-10z0.c"] = 1;
      locks["/domains/core/rooms/east/x290y-40z0.c"] = 1;
      locks["/domains/core/rooms/sewer/x50y60z-10.c"] = 1; 
      save_me();
   }
}

static void restore_me(void) {
   unguarded("restore_object", DATAFILE);

}

static void save_me(void) {
   unguarded("save_object", DATAFILE);
}

void set_lock(string lock, int status) {
  locks[lock] = status;
  save_me();
}

int is_locked(string lock) {
   if (locks[lock] == 0) {
      return 0;
   } else if (locks[lock] == 1) {
      return 1;
   }
}

int is_unlocked(string lock) {
   if (locks[lock] == 0) {
     return 1;
   } else if (locks[lock] == 1) {
     return 0;
   }
}

void remove_lock(string lock) {
   locks[lock] = nil;
   save_me();
}

string *query_locks(void) {
   return map_indices(locks);
}

