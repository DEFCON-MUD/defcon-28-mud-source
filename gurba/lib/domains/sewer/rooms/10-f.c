inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 10-f" );
set_objects( DIR+"/monsters/sub-average_rat_5.c");
 set_exits( ([
  "east" : DIR+"/rooms/10-g.c",
  "west" : DIR+"/rooms/10-e.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the purple glow of the muck in this hellhole. The walls and floors are covered with oil. The air is rather stagnant.%^RESET%^\n\nYou may be able to find escape to the east, and west.%^RESET%^");
}
