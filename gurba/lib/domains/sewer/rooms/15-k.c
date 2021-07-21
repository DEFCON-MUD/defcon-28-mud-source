inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 15-k" );
set_objects( DIR+"/monsters/average_lizard_6.c");
 set_exits( ([
  "east" : DIR+"/rooms/15-l.c",
  "northwest" : DIR+"/rooms/14-j.c",
  "southeast" : DIR+"/rooms/16-l.c"
  ]) );
  set_long( "This is a wide hallway, illuminated only by the iridium glow of the gunk in this hellhole. The walls and floors are covered with liquid. The air is rather stagnant.%^RESET%^\n\nYou may be able to find escape to the east, northwest, and southeast.%^RESET%^");
}
