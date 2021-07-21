inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 7-e" );
set_objects( DIR+"/monsters/sub-average_lizard_5.c");
 set_exits( ([
  "north" : DIR+"/rooms/6-e.c",
  "east" : DIR+"/rooms/7-f.c",
  "west" : DIR+"/rooms/7-d.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the greenish glow of the sediment in this stink-pit. The walls and floors are covered with liquid. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nTunnels can be found to the north, east, and west.%^RESET%^");
}
