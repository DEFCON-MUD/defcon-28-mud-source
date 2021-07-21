inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 17-f" );
set_objects( DIR+"/monsters/sub-average_worm_5.c");
 set_exits( ([
  "east" : DIR+"/rooms/17-g.c",
  "west" : DIR+"/rooms/17-e.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the greenish glow of the gunk in this area. The walls and floors are covered with liquid. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nYou may be able to find escape to the east, and west.%^RESET%^");
}
