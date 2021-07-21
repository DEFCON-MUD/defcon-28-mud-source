inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 12-d" );
set_objects( DIR+"/monsters/strong_worm_7.c");
 set_exits( ([
  "east" : DIR+"/rooms/12-e.c",
  "west" : DIR+"/rooms/12-c.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the red glow of the sediment in this area. The walls and floors are covered with mud. The air is rather stagnant.%^RESET%^\n\nYou may be able to find escape to the east, and west.%^RESET%^");
}
