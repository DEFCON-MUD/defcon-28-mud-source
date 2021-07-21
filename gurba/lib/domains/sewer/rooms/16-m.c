inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 16-m" );
set_objects( DIR+"/monsters/uninitiated_ferret_1.c");
 set_exits( ([
  "east" : DIR+"/rooms/16-n.c",
  "west" : DIR+"/rooms/16-l.c",
  "southeast" : DIR+"/rooms/17-n.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the green glow of the gunk in this stink-pit. The walls and floors are covered with oil. The air is rather stagnant.%^RESET%^\n\nThe horror continues to the east, west, and southeast.%^RESET%^");
}
