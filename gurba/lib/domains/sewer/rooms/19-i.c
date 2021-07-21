inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 19-i" );
set_objects( DIR+"/monsters/sub-average_lizard_5.c");
 set_exits( ([
  "east" : DIR+"/rooms/19-j.c",
  "west" : DIR+"/rooms/19-h.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the orange glow of the muck in this stink-pit. The walls and floors are covered with slime. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nTunnels can be found to the east, and west.%^RESET%^");
}
