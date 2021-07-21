inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 15-q" );
set_objects( DIR+"/monsters/newbie_ferret_2.c");
 set_exits( ([
  "north" : DIR+"/rooms/14-q.c",
  "down" : DIR+"/rooms/100-q.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the red glow of the sediment in this area. The walls and floors are covered with oil. It smells like a hacker convention in here.%^RESET%^\n\nTunnels can be found to the north, and down.%^RESET%^");
}
