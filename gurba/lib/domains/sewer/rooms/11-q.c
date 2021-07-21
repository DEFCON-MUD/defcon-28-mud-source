inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 11-q" );
set_objects( DIR+"/monsters/strong_eel_7.c");
 set_exits( ([
  "south" : DIR+"/rooms/12-q.c",
  "east" : DIR+"/rooms/11-r.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the orange glow of the muck in this hellhole. The walls and floors are covered with dust. The air is rather stagnant.%^RESET%^\n\nThe sewer continues to the south, and east.%^RESET%^");
}
