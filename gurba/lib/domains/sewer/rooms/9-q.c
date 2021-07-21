inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 9-q" );
set_objects( DIR+"/monsters/meh_ferret_3.c");
 set_exits( ([
  "east" : DIR+"/rooms/9-r.c",
  "west" : DIR+"/rooms/9-p.c",
  "northeast" : DIR+"/rooms/8-r.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the orange glow of the gunk in this stink-pit. The walls and floors are covered with oil. The smell is outright dreadful.%^RESET%^\n\nTunnels can be found to the east, west, and northeast.%^RESET%^");
}
