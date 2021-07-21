inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 3-m" );
set_objects( DIR+"/monsters/newbie_rat_2.c");
 set_exits( ([
  "north" : DIR+"/rooms/2-m.c",
  "south" : DIR+"/rooms/4-m.c",
  "northeast" : DIR+"/rooms/2-n.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the greenish glow of the muck in this hellhole. The walls and floors are covered with liquid. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nTunnels can be found to the north, south, and northeast.%^RESET%^");
}
