inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 4-c" );
set_objects( DIR+"/monsters/newbie_worm_2.c");
 set_exits( ([
  "north" : DIR+"/rooms/3-c.c",
  "south" : DIR+"/rooms/5-c.c"
  ]) );
  set_long( "This is a cramped tunnel, illuminated only by the red glow of the sediment in this area. The walls and floors are covered with slime. It smells like a hacker convention in here.%^RESET%^\n\nTunnels can be found to the north, and south.%^RESET%^");
}
