inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 6-m" );
set_objects( DIR+"/monsters/average_lizard_6.c");
 set_exits( ([
  "north" : DIR+"/rooms/5-m.c",
  "east" : DIR+"/rooms/6-n.c"
  ]) );
  set_long( "This is a wide corridor, illuminated only by the purple glow of the muck in this area. The walls and floors are covered with dust. It smells like a hacker convention in here.%^RESET%^\n\nThe sewer continues to the north, and east.%^RESET%^");
}
