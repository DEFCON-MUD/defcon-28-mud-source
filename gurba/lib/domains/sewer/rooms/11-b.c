inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 11-b" );
set_objects( DIR+"/monsters/sub-average_worm_5.c");
 set_exits( ([
  "east" : DIR+"/rooms/11-c.c",
  "northwest" : DIR+"/rooms/10-a.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the iridium glow of the gunk in this hellhole. The walls and floors are covered with slime. The smell is outright dreadful.%^RESET%^\n\nTunnels can be found to the east, and northwest.%^RESET%^");
}
