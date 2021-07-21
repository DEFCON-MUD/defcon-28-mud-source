inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 8-a" );
set_objects( DIR+"/monsters/newbie_lizard_2.c");
 set_exits( ([
  "south" : DIR+"/rooms/9-a.c"
  ]) );
  set_long( "This is a wide hallway, illuminated only by the greenish glow of the sediment in this area. The walls and floors are covered with liquid. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nTunnels can be found to the south.%^RESET%^");
}
