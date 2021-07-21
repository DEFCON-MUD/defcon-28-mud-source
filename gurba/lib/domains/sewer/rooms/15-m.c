inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 15-m" );
set_objects( DIR+"/monsters/strong_snake_7.c");
 set_exits( ([
  "east" : DIR+"/rooms/15-n.c",
  "west" : DIR+"/rooms/15-l.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the purple glow of the muck in this area. The walls and floors are covered with liquid. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nTunnels can be found to the east, and west.%^RESET%^");
}
