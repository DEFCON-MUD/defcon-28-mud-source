inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 2-d" );
set_objects( DIR+"/monsters/sub-average_rat_5.c");
 set_exits( ([
  "south" : DIR+"/rooms/3-d.c",
  "east" : DIR+"/rooms/2-e.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the red glow of the sediment in this hellhole. The walls and floors are covered with dust. It smells like a hacker convention in here.%^RESET%^\n\nTunnels can be found to the south, and east.%^RESET%^");
}
