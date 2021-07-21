inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 14-a" );
set_objects( DIR+"/monsters/uninitiated_ferret_1.c");
 set_exits( ([
  "north" : DIR+"/rooms/13-a.c",
  "southeast" : DIR+"/rooms/15-b.c"
  ]) );
  set_long( "This is a narrow hallway, illuminated only by the redish glow of the gunk in this stink-pit. The walls and floors are covered with oil. It smells like a hacker convention in here.%^RESET%^\n\nTunnels can be found to the north, and southeast.%^RESET%^");
}
