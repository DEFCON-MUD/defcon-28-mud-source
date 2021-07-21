inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 13-c" );
set_objects( DIR+"/monsters/sub-average_worm_5.c");
 set_exits( ([
  "east" : DIR+"/rooms/13-d.c",
  "west" : DIR+"/rooms/13-b.c",
  "southeast" : DIR+"/rooms/14-d.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the greenish glow of the gunk in this stink-pit. The walls and floors are covered with dust. The smell is outright dreadful.%^RESET%^\n\nTunnels can be found to the east, west, and southeast.%^RESET%^");
}
