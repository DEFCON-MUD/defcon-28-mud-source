inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 100-j" );
set_objects( DIR+"/monsters/parrot.c");

 set_exits( ([
  "up" : DIR+"/rooms/9-j.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the orange glow of the muck in this stink-pit. The walls and floors are covered with dust. The air is rather stagnant. You see footprints in the gunk...%^RESET%^\n\nTunnels can be found to the up.%^RESET%^");
}

int do_search(void) {
   this_environment()->setup();
   write("An animal appears out of the woodwork");
   return 1;
}