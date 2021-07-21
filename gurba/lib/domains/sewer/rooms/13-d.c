inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 13-d" );
set_objects( DIR+"/monsters/newbie_ferret_2.c");
 set_exits( ([
  "south" : DIR+"/rooms/14-d.c",
  "west" : DIR+"/rooms/13-c.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the greenish glow of the muck in this area. The walls and floors are covered with oil. The smell is outright dreadful.%^RESET%^\n\nTunnels can be found to the south, and west.%^RESET%^");
}
