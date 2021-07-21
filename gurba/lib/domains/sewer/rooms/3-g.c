inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 3-g" );
set_objects( DIR+"/monsters/strong_worm_7.c");
 set_exits( ([
  "northwest" : DIR+"/rooms/2-f.c",
  "southeast" : DIR+"/rooms/4-h.c"
  ]) );
  set_long( "This is a narrow hallway, illuminated only by the iridium glow of the muck in this stink-pit. The walls and floors are covered with blood. It smells like a hacker convention in here.%^RESET%^\n\nThe sewer continues to the northwest, and southeast.%^RESET%^");
}
