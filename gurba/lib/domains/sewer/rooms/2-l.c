inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 2-l" );
set_objects( DIR+"/monsters/uninitiated_eel_1.c");
 set_exits( ([
  "south" : DIR+"/rooms/3-l.c",
  "west" : DIR+"/rooms/2-k.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the greenish glow of the muck in this stink-pit. The walls and floors are covered with oil. The air is rather stagnant.%^RESET%^\n\nYou may be able to find escape to the south, and west.%^RESET%^");
}
