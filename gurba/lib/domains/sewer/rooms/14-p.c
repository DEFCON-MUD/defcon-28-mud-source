inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 14-p" );
set_objects( DIR+"/monsters/average_lizard_6.c");
 set_exits( ([
  "east" : DIR+"/rooms/14-q.c",
  "west" : DIR+"/rooms/14-o.c"
  ]) );
  set_long( "This is a wide corridor, illuminated only by the red glow of the gunk in this stink-pit. The walls and floors are covered with liquid. The air is rather stagnant.%^RESET%^\n\nThe horror continues to the east, and west.%^RESET%^");
}
