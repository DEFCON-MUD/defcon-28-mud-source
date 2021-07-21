inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 15-f" );
set_objects( DIR+"/monsters/uninitiated_lizard_1.c");
 set_exits( ([
  "north" : DIR+"/rooms/14-f.c",
  "west" : DIR+"/rooms/15-e.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the green glow of the sediment in this area. The walls and floors are covered with slime. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nTunnels can be found to the north, and west.%^RESET%^");
}
