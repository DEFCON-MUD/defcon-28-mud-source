inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 3-c" );
set_objects( DIR+"/monsters/meh_snake_3.c");
 set_exits( ([
  "south" : DIR+"/rooms/4-c.c",
  "southwest" : DIR+"/rooms/4-b.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the redish glow of the gunk in this area. The walls and floors are covered with blood. The air is rather stagnant.%^RESET%^\n\nTunnels can be found to the south, and southwest.%^RESET%^");
}
