inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 5-b" );
set_objects( DIR+"/monsters/newbie_rat_2.c");
 set_exits( ([
  "north" : DIR+"/rooms/4-b.c",
  "south" : DIR+"/rooms/6-b.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the green glow of the gunk in this area. The walls and floors are covered with slime. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nTunnels can be found to the north, and south.%^RESET%^");
}
