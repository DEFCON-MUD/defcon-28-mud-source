inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 10-h" );
set_objects( DIR+"/monsters/mediocre_snake_4.c");
 set_exits( ([
  "east" : DIR+"/rooms/10-i.c",
  "west" : DIR+"/rooms/10-g.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the greenish glow of the gunk in this hellhole. The walls and floors are covered with slime. The air is rather stagnant.%^RESET%^\n\nThe sewer continues to the east, and west.%^RESET%^");
}
