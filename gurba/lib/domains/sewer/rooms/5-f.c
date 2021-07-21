inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 5-f" );
set_objects( DIR+"/monsters/newbie_snake_2.c");
 set_exits( ([
  "north" : DIR+"/rooms/4-f.c",
  "southeast" : DIR+"/rooms/6-g.c"
  ]) );
  set_long( "This is a cramped tunnel, illuminated only by the greenish glow of the sediment in this hellhole. The walls and floors are covered with slime. The air is rather stagnant.%^RESET%^\n\nTunnels can be found to the north, and southeast.%^RESET%^");
}
