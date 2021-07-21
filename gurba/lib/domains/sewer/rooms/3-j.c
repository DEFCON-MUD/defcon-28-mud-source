inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 3-j" );
set_objects( DIR+"/monsters/uninitiated_rat_1.c");
 set_exits( ([
  "north" : DIR+"/rooms/2-j.c",
  "south" : DIR+"/rooms/4-j.c"
  ]) );
  set_long( "This is a narrow hallway, illuminated only by the greenish glow of the sediment in this hellhole. The walls and floors are covered with liquid. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nTunnels can be found to the north, and south.%^RESET%^");
}
