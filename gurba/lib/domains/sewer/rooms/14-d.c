inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 14-d" );
set_objects( DIR+"/monsters/average_parrot_6.c");
 set_exits( ([
  "north" : DIR+"/rooms/13-d.c",
  "west" : DIR+"/rooms/14-c.c",
  "northwest" : DIR+"/rooms/13-c.c"
  ]) );
  set_long( "This is a wide hallway, illuminated only by the green glow of the sediment in this stink-pit. The walls and floors are covered with dust. The air is rather stagnant.%^RESET%^\n\nTunnels can be found to the north, west, and northwest.%^RESET%^");
}
