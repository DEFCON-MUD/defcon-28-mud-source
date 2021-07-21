inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 18-g" );
set_objects( DIR+"/monsters/sub-average_mouse_5.c");
 set_exits( ([
  "north" : DIR+"/rooms/17-g.c",
  "east" : DIR+"/rooms/18-h.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the redish glow of the sediment in this hellhole. The walls and floors are covered with dust. It smells like a hacker convention in here.%^RESET%^\n\nTunnels can be found to the north, and east.%^RESET%^");
}
