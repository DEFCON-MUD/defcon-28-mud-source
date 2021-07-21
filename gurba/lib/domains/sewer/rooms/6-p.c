inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 6-p" );
set_objects( DIR+"/monsters/average_snake_6.c");
 set_exits( ([
  "north" : DIR+"/rooms/5-p.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the red glow of the muck in this area. The walls and floors are covered with mud. It smells like a hacker convention in here.%^RESET%^\n\nYou may be able to find escape to the north.%^RESET%^");
}
