inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 10-g" );
set_objects( DIR+"/monsters/strong_lizard_7.c");
 set_exits( ([
  "east" : DIR+"/rooms/10-h.c",
  "west" : DIR+"/rooms/10-f.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the purple glow of the gunk in this hellhole. The walls and floors are covered with oil. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe sewer continues to the east, and west.%^RESET%^");
}
