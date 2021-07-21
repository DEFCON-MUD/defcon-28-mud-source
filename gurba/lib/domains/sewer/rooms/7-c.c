inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 7-c" );
set_objects( DIR+"/monsters/newbie_alligator_2.c");
 set_exits( ([
  "east" : DIR+"/rooms/7-d.c",
  "west" : DIR+"/rooms/7-b.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the greenish glow of the sediment in this area. The walls and floors are covered with oil. The air is rather stagnant.%^RESET%^\n\nTunnels can be found to the east, and west.%^RESET%^");
}
