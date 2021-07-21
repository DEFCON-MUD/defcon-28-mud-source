inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 14-s" );
set_objects( DIR+"/monsters/mediocre_alligator_4.c");
 set_exits( ([
  "west" : DIR+"/rooms/14-r.c",
  "southwest" : DIR+"/rooms/15-r.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the greenish glow of the sediment in this hellhole. The walls and floors are covered with mud. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nYou may be able to find escape to the west, and southwest.%^RESET%^");
}
