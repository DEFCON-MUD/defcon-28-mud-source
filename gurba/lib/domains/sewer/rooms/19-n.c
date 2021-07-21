inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 19-n" );
set_objects( DIR+"/monsters/sub-average_worm_5.c");
 set_exits( ([
  "west" : DIR+"/rooms/19-m.c",
  "northeast" : DIR+"/rooms/18-o.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the redish glow of the sediment in this hellhole. The walls and floors are covered with mud. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nYou may be able to find escape to the west, and northeast.%^RESET%^");
}
