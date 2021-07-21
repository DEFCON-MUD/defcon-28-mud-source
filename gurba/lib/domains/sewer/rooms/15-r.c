inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 15-r" );
set_objects( DIR+"/monsters/meh_parrot_3.c");
 set_exits( ([
  "south" : DIR+"/rooms/16-r.c",
  "northeast" : DIR+"/rooms/14-s.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the green glow of the gunk in this stink-pit. The walls and floors are covered with oil. The air is rather stagnant.%^RESET%^\n\nTunnels can be found to the south, and northeast.%^RESET%^");
}
