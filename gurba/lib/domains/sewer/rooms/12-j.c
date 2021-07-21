inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 12-j" );
set_objects( DIR+"/monsters/uninitiated_lizard_1.c");
 set_exits( ([
  "north" : DIR+"/rooms/11-j.c",
  "south" : DIR+"/rooms/13-j.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the red glow of the gunk in this stink-pit. The walls and floors are covered with mud. The air is rather stagnant.%^RESET%^\n\nTunnels can be found to the north, and south.%^RESET%^");
}
