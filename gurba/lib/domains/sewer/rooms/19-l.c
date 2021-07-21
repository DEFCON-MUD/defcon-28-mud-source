inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 19-l" );
set_objects( DIR+"/monsters/meh_parrot_3.c");
 set_exits( ([
  "east" : DIR+"/rooms/19-m.c",
  "west" : DIR+"/rooms/19-k.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the redish glow of the gunk in this hellhole. The walls and floors are covered with liquid. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nTunnels can be found to the east, and west.%^RESET%^");
}
