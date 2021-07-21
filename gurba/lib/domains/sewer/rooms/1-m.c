inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 1-m" );
set_objects( DIR+"/monsters/sub-average_worm_5.c");
 set_exits( ([
  "south" : DIR+"/rooms/2-m.c",
  "west" : DIR+"/rooms/1-l.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the greenish glow of the muck in this hellhole. The walls and floors are covered with liquid. The smell is outright dreadful.%^RESET%^\n\nYou may be able to find escape to the south, and west.%^RESET%^");
}
