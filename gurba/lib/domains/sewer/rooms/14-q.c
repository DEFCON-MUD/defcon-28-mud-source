inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 14-q" );
set_objects( DIR+"/monsters/newbie_rat_2.c");
 set_exits( ([
  "south" : DIR+"/rooms/15-q.c",
  "east" : DIR+"/rooms/14-r.c",
  "west" : DIR+"/rooms/14-p.c",
  "southwest" : DIR+"/rooms/15-p.c"
  ]) );
  set_long( "This is a wide hallway, illuminated only by the greenish glow of the sediment in this hellhole. The walls and floors are covered with dust. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nTunnels can be found to the south, east, west, and southwest.%^RESET%^");
}
