inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 10-k" );
set_objects( DIR+"/monsters/meh_rat_3.c");
 set_exits( ([
  "east" : DIR+"/rooms/10-l.c",
  "southeast" : DIR+"/rooms/11-l.c"
  ]) );
  set_long( "This is a wide corridor, illuminated only by the redish glow of the sediment in this hellhole. The walls and floors are covered with blood. The air is rather stagnant.%^RESET%^\n\nYou may be able to find escape to the east, and southeast.%^RESET%^");
}
