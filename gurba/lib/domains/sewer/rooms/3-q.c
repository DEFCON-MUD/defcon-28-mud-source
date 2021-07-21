inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 3-q" );
set_objects( DIR+"/monsters/sub-average_eel_5.c");
 set_exits( ([
  "south" : DIR+"/rooms/4-q.c",
  "northwest" : DIR+"/rooms/2-p.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the redish glow of the sediment in this area. The walls and floors are covered with slime. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nTunnels can be found to the south, and northwest.%^RESET%^");
}
