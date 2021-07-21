inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 10-c" );
set_objects( DIR+"/monsters/uninitiated_ferret_1.c");
 set_exits( ([
  "east" : DIR+"/rooms/10-d.c",
  "west" : DIR+"/rooms/10-b.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the green glow of the sediment in this stink-pit. The walls and floors are covered with mud. The air is rather stagnant.%^RESET%^\n\nThe horror continues to the east, and west.%^RESET%^");
}
