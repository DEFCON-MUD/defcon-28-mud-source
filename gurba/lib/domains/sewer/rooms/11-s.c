inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 11-s" );
set_objects( DIR+"/monsters/newbie_ferret_2.c");
 set_exits( ([
  "south" : DIR+"/rooms/12-s.c",
  "west" : DIR+"/rooms/11-r.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the purple glow of the sediment in this stink-pit. The walls and floors are covered with oil. It smells like a hacker convention in here.%^RESET%^\n\nTunnels can be found to the south, and west.%^RESET%^");
}
