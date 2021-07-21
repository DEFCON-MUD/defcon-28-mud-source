inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 2-e" );
set_objects( DIR+"/monsters/mediocre_lizard_4.c");
 set_exits( ([
  "west" : DIR+"/rooms/2-d.c",
  "northeast" : DIR+"/rooms/1-f.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the greenish glow of the muck in this stink-pit. The walls and floors are covered with blood. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nTunnels can be found to the west, and northeast.%^RESET%^");
}
