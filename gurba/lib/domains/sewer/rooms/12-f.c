inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 12-f" );
set_objects( DIR+"/monsters/average_eel_6.c");
 set_exits( ([
  "south" : DIR+"/rooms/13-f.c",
  "east" : DIR+"/rooms/12-g.c",
  "west" : DIR+"/rooms/12-e.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the red glow of the muck in this hellhole. The walls and floors are covered with blood. The air is rather stagnant.%^RESET%^\n\nYou may be able to find escape to the south, east, and west.%^RESET%^");
}
