inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 18-n" );
set_objects( DIR+"/monsters/sub-average_parrot_5.c");
 set_exits( ([
  "north" : DIR+"/rooms/17-n.c",
  "east" : DIR+"/rooms/18-o.c",
  "west" : DIR+"/rooms/18-m.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the purple glow of the muck in this area. The walls and floors are covered with oil. The smell is outright dreadful.%^RESET%^\n\nTunnels can be found to the north, east, and west.%^RESET%^");
}
