void restore_me(void);
void save_me(void);
#define DATAFILE "/daemons/data/evil/dark_d.o"

mapping darks;
int east_dome;
int callout_handle;
 
void create(void) {

   darks =([ ]);
   east_dome = 0;
   callout_handle = 0;


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

void set_dark(string dark) {
  darks[dark] = 1;
  save_me();
}

int is_dark(string dark) {
   if (darks[dark] == 1) {
      return 1;
   }

   return 0;
}

void remove_dark(string dark) {
   darks[dark] = nil;
   save_me();
}

string *query_darks(void) {
   return map_indices(darks);
}


int flip_east(int state) {
  if (east_dome == 1) {
    if(callout_handle != 0) {
        remove_call_out(callout_handle);
        callout_handle = 0;
    }
    state = 0;
  }
  if(state == 1) {
     DARK_D->set_dark("/domains/core/rooms/east/x210y100z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x220y-10z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x220y-20z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x220y-30z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x220y-40z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x230y-20z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x230y-30z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x230y-40z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x230y-50z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x240y-10z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x240y-20z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x240y-30z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x240y-40z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x240y-50z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x250y-10z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x250y-20z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x250y-30z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x250y-40z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x250y-50z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x260y-10z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x260y-20z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x260y-30z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x260y-50z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x270y-10z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x270y-30z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x270y-40z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x270y-50z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x270y-60z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x280y-10z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x280y-20z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x280y-30z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x280y-40z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x280y-50z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x280y-60z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x290y-10z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x290y-20z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x290y-40z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x290y-50z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x290y-60z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x300y-10z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x300y-20z0.c");
     DARK_D->set_dark("/domains/core/rooms/east/x300y-40z0.c");
     LOCK_D->set_lock("/domains/core/rooms/east/x290y-40z0.c", 0);
     LOCK_D->set_lock("/domains/core/rooms/east/x240y-10z0.c", 0);
     LOCK_D->set_lock("/domains/core/rooms/east/x230y-50z0.c", 0);
     CHANNEL_D->chan_send_string("announce", "", "Electrical failure in the East Dome, all available technicians please investigate!!!", 1);
     callout_handle = call_out("flip_east", 300, 0);
     east_dome = 1;
     return 1;
  } else if (state == 0) {
     DARK_D->remove_dark("/domains/core/rooms/east/x210y100z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x220y-10z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x220y-20z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x220y-30z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x220y-40z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x230y-20z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x230y-30z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x230y-40z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x230y-50z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x240y-10z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x240y-20z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x240y-30z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x240y-40z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x240y-50z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x250y-10z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x250y-20z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x250y-30z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x250y-40z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x250y-50z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x260y-10z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x260y-20z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x260y-30z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x260y-50z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x270y-10z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x270y-30z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x270y-40z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x270y-50z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x270y-60z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x280y-10z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x280y-20z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x280y-30z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x280y-40z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x280y-50z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x280y-60z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x290y-10z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x290y-20z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x290y-40z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x290y-50z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x290y-60z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x300y-10z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x300y-20z0.c");
     DARK_D->remove_dark("/domains/core/rooms/east/x300y-40z0.c");
     LOCK_D->set_lock("/domains/core/rooms/east/x290y-40z0.c", 1);
     LOCK_D->set_lock("/domains/core/rooms/east/x240y-10z0.c", 1);
     LOCK_D->set_lock("/domains/core/rooms/east/x230y-50z0.c", 1);
     east_dome = 0;
     CHANNEL_D->chan_send_string("announce", "", "East Dome Electrical Failure Resolved, all systems nominal...", 1);
     return 1;
  }
  return 0;
}
