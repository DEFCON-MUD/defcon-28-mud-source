inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 12-c" );
set_objects( DIR+"/monsters/newbie_alligator_2.c");
 set_exits( ([
  "east" : DIR+"/rooms/12-d.c",
  "west" : DIR+"/rooms/12-b.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the iridium glow of the gunk in this area. The walls and floors are covered with liquid. It smells like a hacker convention in here.%^RESET%^\n\nTunnels can be found to the east, and west.%^RESET%^");
}
