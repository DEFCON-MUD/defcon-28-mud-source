inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 18-i" );
set_objects( DIR+"/monsters/newbie_rat_2.c");
 set_exits( ([
  "north" : DIR+"/rooms/17-i.c",
  "southwest" : DIR+"/rooms/19-h.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the redish glow of the muck in this hellhole. The walls and floors are covered with dust. It smells like a hacker convention in here.%^RESET%^\n\nTunnels can be found to the north, and southwest.%^RESET%^");
}
