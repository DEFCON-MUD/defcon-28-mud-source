inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 3-d" );
set_objects( DIR+"/monsters/average_snake_6.c");
 set_exits( ([
  "north" : DIR+"/rooms/2-d.c",
  "south" : DIR+"/rooms/4-d.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the red glow of the sediment in this area. The walls and floors are covered with mud. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nTunnels can be found to the north, and south.%^RESET%^");
}
