inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 3-i" );
set_objects( DIR+"/monsters/sub-average_mouse_5.c");
 set_exits( ([
  "north" : DIR+"/rooms/2-i.c",
  "west" : DIR+"/rooms/3-h.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the greenish glow of the gunk in this hellhole. The walls and floors are covered with liquid. It smells like a hacker convention in here.%^RESET%^\n\nTunnels can be found to the north, and west.%^RESET%^");
}
