inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 100-q" );
set_objects( DIR+"/monsters/rat.c");
 set_exits( ([
  "up" : DIR+"/rooms/15-q.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the orange glow of the sediment in this area. The walls and floors are covered with oil. The smell is outright dreadful.%^RESET%^\n\nTunnels can be found to the up.%^RESET%^");
}
