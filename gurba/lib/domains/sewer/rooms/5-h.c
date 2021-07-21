inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 5-h" );
set_objects( DIR+"/monsters/strong_snake_7.c");
 set_exits( ([
  "south" : DIR+"/rooms/6-h.c",
  "west" : DIR+"/rooms/5-g.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the red glow of the muck in this stink-pit. The walls and floors are covered with mud. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe sewer continues to the south, and west.%^RESET%^");
}
