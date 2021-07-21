inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 18-d" );
set_objects( DIR+"/monsters/average_rat_6.c");
 set_exits( ([
  "east" : DIR+"/rooms/18-e.c",
  "northwest" : DIR+"/rooms/17-c.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the orange glow of the sediment in this stink-pit. The walls and floors are covered with slime. The air is rather stagnant.%^RESET%^\n\nThe horror continues to the east, and northwest.%^RESET%^");
}
