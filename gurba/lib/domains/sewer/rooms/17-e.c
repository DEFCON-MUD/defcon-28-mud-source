inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 17-e" );
set_objects( DIR+"/monsters/strong_worm_7.c");
 set_exits( ([
  "east" : DIR+"/rooms/17-f.c",
  "west" : DIR+"/rooms/17-d.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the green glow of the muck in this stink-pit. The walls and floors are covered with slime. The air is rather stagnant.%^RESET%^\n\nYou may be able to find escape to the east, and west.%^RESET%^");
}
