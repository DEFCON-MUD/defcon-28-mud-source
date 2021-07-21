inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 2-j" );
set_objects( DIR+"/monsters/uninitiated_ferret_1.c");
 set_exits( ([
  "north" : DIR+"/rooms/1-j.c",
  "south" : DIR+"/rooms/3-j.c",
  "northwest" : DIR+"/rooms/1-i.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the greenish glow of the sediment in this stink-pit. The walls and floors are covered with blood. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nTunnels can be found to the north, south, and northwest.%^RESET%^");
}
