inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 1-h" );
set_objects( DIR+"/monsters/newbie_worm_2.c");
 set_exits( ([
  "east" : DIR+"/rooms/1-i.c",
  "west" : DIR+"/rooms/1-g.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the redish glow of the gunk in this stink-pit. The walls and floors are covered with blood. It smells like a hacker convention in here.%^RESET%^\n\nTunnels can be found to the east, and west.%^RESET%^");
}
