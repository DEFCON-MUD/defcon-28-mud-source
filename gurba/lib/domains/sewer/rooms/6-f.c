inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 6-f" );
set_objects( DIR+"/monsters/mediocre_parrot_4.c");
 set_exits( ([
  "west" : DIR+"/rooms/6-e.c",
  "northwest" : DIR+"/rooms/5-e.c",
  "southeast" : DIR+"/rooms/7-g.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the greenish glow of the sediment in this hellhole. The walls and floors are covered with dust. It smells like a hacker convention in here.%^RESET%^\n\nTunnels can be found to the west, northwest, and southeast.%^RESET%^");
}
