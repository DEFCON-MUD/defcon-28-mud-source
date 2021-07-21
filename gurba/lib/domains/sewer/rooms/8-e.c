inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 8-e" );
set_objects( DIR+"/monsters/uninitiated_alligator_1.c");
 set_exits( ([
  "south" : DIR+"/rooms/9-e.c",
  "east" : DIR+"/rooms/8-f.c"
  ]) );
  set_long( "This is a narrow corridor, illuminated only by the red glow of the muck in this stink-pit. The walls and floors are covered with oil. The air is rather stagnant.%^RESET%^\n\nThe horror continues to the south, and east.%^RESET%^");
}
