inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 16-l" );
set_objects( DIR+"/monsters/uninitiated_rat_1.c");
 set_exits( ([
  "east" : DIR+"/rooms/16-m.c",
  "northwest" : DIR+"/rooms/15-k.c"
  ]) );
  set_long( "This is a wide corridor, illuminated only by the orange glow of the gunk in this hellhole. The walls and floors are covered with oil. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nTunnels can be found to the east, and northwest.%^RESET%^");
}
