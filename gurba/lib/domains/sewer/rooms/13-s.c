inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 13-s" );
set_objects( DIR+"/monsters/meh_ferret_3.c");
 set_exits( ([
  "north" : DIR+"/rooms/12-s.c",
  "southwest" : DIR+"/rooms/14-r.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the greenish glow of the muck in this hellhole. The walls and floors are covered with slime. It smells like a hacker convention in here.%^RESET%^\n\nYou may be able to find escape to the north, and southwest.%^RESET%^");
}
