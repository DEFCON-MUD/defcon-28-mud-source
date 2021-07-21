inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 13-g" );
set_objects( DIR+"/monsters/sub-average_ferret_5.c");
 set_exits( ([
  "north" : DIR+"/rooms/12-g.c",
  "south" : DIR+"/rooms/14-g.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the red glow of the gunk in this area. The walls and floors are covered with dust. The air is rather stagnant.%^RESET%^\n\nThe sewer continues to the north, and south.%^RESET%^");
}
