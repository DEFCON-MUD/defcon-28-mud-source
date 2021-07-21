inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 5-p" );
set_objects( DIR+"/monsters/newbie_ferret_2.c");
 set_exits( ([
  "north" : DIR+"/rooms/4-p.c",
  "south" : DIR+"/rooms/6-p.c",
  "southwest" : DIR+"/rooms/6-o.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the green glow of the sediment in this stink-pit. The walls and floors are covered with mud. The air is rather stagnant.%^RESET%^\n\nThe horror continues to the north, south, and southwest.%^RESET%^");
}
