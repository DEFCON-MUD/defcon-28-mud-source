inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 8-k" );
set_objects( DIR+"/monsters/strong_lizard_7.c");
 set_exits( ([
  "south" : DIR+"/rooms/9-k.c",
  "west" : DIR+"/rooms/8-j.c",
  "northeast" : DIR+"/rooms/7-l.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the green glow of the gunk in this hellhole. The walls and floors are covered with slime. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nTunnels can be found to the south, west, and northeast.%^RESET%^");
}
