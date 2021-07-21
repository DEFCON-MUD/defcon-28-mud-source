inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 2-n" );
set_objects( DIR+"/monsters/sub-average_mouse_5.c");
 set_exits( ([
  "north" : DIR+"/rooms/1-n.c",
  "east" : DIR+"/rooms/2-o.c",
  "southwest" : DIR+"/rooms/3-m.c"
  ]) );
  set_long( "This is a narrow corridor, illuminated only by the iridium glow of the muck in this stink-pit. The walls and floors are covered with mud. The air is rather stagnant.%^RESET%^\n\nThe horror continues to the north, east, and southwest.%^RESET%^");
}
