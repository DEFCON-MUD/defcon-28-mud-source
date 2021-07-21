inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 14-k" );
set_objects( DIR+"/monsters/mediocre_alligator_4.c");
 set_exits( ([
  "north" : DIR+"/rooms/13-k.c",
  "southeast" : DIR+"/rooms/15-l.c"
  ]) );
  set_long( "This is a cramped tunnel, illuminated only by the green glow of the sediment in this hellhole. The walls and floors are covered with liquid. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nTunnels can be found to the north, and southeast.%^RESET%^");
}
