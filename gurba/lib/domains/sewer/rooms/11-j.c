inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 11-j" );
set_objects( DIR+"/monsters/newbie_eel_2.c");
 set_exits( ([
  "south" : DIR+"/rooms/12-j.c",
  "southeast" : DIR+"/rooms/12-k.c"
  ]) );
  set_long( "This is a cramped tunnel, illuminated only by the orange glow of the sediment in this area. The walls and floors are covered with slime. It smells like a hacker convention in here.%^RESET%^\n\nTunnels can be found to the south, and southeast.%^RESET%^");
}
