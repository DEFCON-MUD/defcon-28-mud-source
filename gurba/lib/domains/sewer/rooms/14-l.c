inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 14-l" );
set_objects( DIR+"/monsters/sub-average_worm_5.c");
 set_exits( ([
  "north" : DIR+"/rooms/13-l.c",
  "east" : DIR+"/rooms/14-m.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the green glow of the muck in this area. The walls and floors are covered with mud. It smells like a hacker convention in here.%^RESET%^\n\nThe horror continues to the north, and east.%^RESET%^");
}
