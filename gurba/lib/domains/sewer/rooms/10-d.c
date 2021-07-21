inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 10-d" );
set_objects( DIR+"/monsters/newbie_snake_2.c");
 set_exits( ([
  "east" : DIR+"/rooms/10-e.c",
  "west" : DIR+"/rooms/10-c.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the redish glow of the muck in this area. The walls and floors are covered with liquid. The air is rather stagnant.%^RESET%^\n\nThe sewer continues to the east, and west.%^RESET%^");
}
