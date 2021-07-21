inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 7-n" );
set_objects( DIR+"/monsters/uninitiated_alligator_1.c");
 set_exits( ([
  "east" : DIR+"/rooms/7-o.c",
  "west" : DIR+"/rooms/7-m.c"
  ]) );
  set_long( "This is a wide corridor, illuminated only by the red glow of the gunk in this stink-pit. The walls and floors are covered with dust. The air is rather stagnant.%^RESET%^\n\nThe horror continues to the east, and west.%^RESET%^");
}
