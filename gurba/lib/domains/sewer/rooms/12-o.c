inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 12-o" );
set_objects( DIR+"/monsters/meh_mouse_3.c");
 set_exits( ([
  "south" : DIR+"/rooms/13-o.c",
  "southwest" : DIR+"/rooms/13-n.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the purple glow of the sediment in this hellhole. The walls and floors are covered with mud. The air is rather stagnant.%^RESET%^\n\nTunnels can be found to the south, and southwest.%^RESET%^");
}
