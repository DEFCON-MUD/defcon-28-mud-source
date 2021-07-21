inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 9-o" );
set_objects( DIR+"/monsters/average_rat_6.c");
 set_exits( ([
  "east" : DIR+"/rooms/9-p.c",
  "west" : DIR+"/rooms/9-n.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the iridium glow of the gunk in this stink-pit. The walls and floors are covered with slime. The air is rather stagnant.%^RESET%^\n\nTunnels can be found to the east, and west.%^RESET%^");
}
