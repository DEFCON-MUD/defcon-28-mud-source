inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 11-d" );
set_objects( DIR+"/monsters/strong_worm_7.c");
 set_exits( ([
  "east" : DIR+"/rooms/11-e.c",
  "west" : DIR+"/rooms/11-c.c"
  ]) );
  set_long( "This is a narrow corridor, illuminated only by the iridium glow of the gunk in this hellhole. The walls and floors are covered with mud. It smells like a hacker convention in here.%^RESET%^\n\nTunnels can be found to the east, and west.%^RESET%^");
}
