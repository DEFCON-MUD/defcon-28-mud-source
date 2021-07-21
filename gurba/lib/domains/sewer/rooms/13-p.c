inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 13-p" );
set_objects( DIR+"/monsters/sub-average_ferret_5.c");
 set_exits( ([
  "north" : DIR+"/rooms/12-p.c",
  "east" : DIR+"/rooms/13-q.c",
  "west" : DIR+"/rooms/13-o.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the green glow of the gunk in this hellhole. The walls and floors are covered with liquid. The smell is outright dreadful.%^RESET%^\n\nTunnels can be found to the north, east, and west.%^RESET%^");
}
