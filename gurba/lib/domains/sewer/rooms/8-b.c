inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 8-b" );
set_objects( DIR+"/monsters/meh_ferret_3.c");
 set_exits( ([
  "northwest" : DIR+"/rooms/7-a.c",
  "southeast" : DIR+"/rooms/9-c.c",
  "southwest" : DIR+"/rooms/9-a.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the greenish glow of the muck in this stink-pit. The walls and floors are covered with oil. It smells like a hacker convention in here.%^RESET%^\n\nTunnels can be found to the northwest, southeast, and southwest.%^RESET%^");
}
