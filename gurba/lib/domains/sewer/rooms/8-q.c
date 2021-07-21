inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 8-q" );
set_objects( DIR+"/monsters/sub-average_ferret_5.c");
 set_exits( ([
  "north" : DIR+"/rooms/7-q.c",
  "southwest" : DIR+"/rooms/9-p.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the orange glow of the sediment in this area. The walls and floors are covered with mud. It smells like a hacker convention in here.%^RESET%^\n\nTunnels can be found to the north, and southwest.%^RESET%^");
}
