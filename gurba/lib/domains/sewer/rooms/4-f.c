inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 4-f" );
set_objects( DIR+"/monsters/strong_mouse_7.c");
 set_exits( ([
  "south" : DIR+"/rooms/5-f.c",
  "east" : DIR+"/rooms/4-g.c"
  ]) );
  set_long( "This is a cramped tunnel, illuminated only by the greenish glow of the sediment in this area. The walls and floors are covered with slime. The air is rather stagnant.%^RESET%^\n\nYou may be able to find escape to the south, and east.%^RESET%^");
}
