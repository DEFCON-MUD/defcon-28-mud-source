inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 9-m" );
set_objects( DIR+"/monsters/meh_mouse_3.c");
 set_exits( ([
  "north" : DIR+"/rooms/8-m.c",
  "east" : DIR+"/rooms/9-n.c",
  "west" : DIR+"/rooms/9-l.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the green glow of the sediment in this stink-pit. The walls and floors are covered with oil. The air is rather stagnant.%^RESET%^\n\nTunnels can be found to the north, east, and west.%^RESET%^");
}
