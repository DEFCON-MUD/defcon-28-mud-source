inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 7-m" );
set_objects( DIR+"/monsters/sub-average_eel_5.c");
 set_exits( ([
  "east" : DIR+"/rooms/7-n.c",
  "northwest" : DIR+"/rooms/6-l.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the orange glow of the gunk in this hellhole. The walls and floors are covered with oil. It smells like a hacker convention in here.%^RESET%^\n\nTunnels can be found to the east, and northwest.%^RESET%^");
}
