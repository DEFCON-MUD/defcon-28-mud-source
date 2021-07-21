inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 9-r" );
set_objects( DIR+"/monsters/strong_snake_7.c");
 set_exits( ([
  "east" : DIR+"/rooms/9-s.c",
  "west" : DIR+"/rooms/9-q.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the orange glow of the sediment in this hellhole. The walls and floors are covered with blood. The smell is outright dreadful.%^RESET%^\n\nYou may be able to find escape to the east, and west.%^RESET%^");
}
