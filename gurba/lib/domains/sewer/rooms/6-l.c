inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 6-l" );
set_objects( DIR+"/monsters/strong_worm_7.c");
 set_exits( ([
  "northwest" : DIR+"/rooms/5-k.c",
  "southeast" : DIR+"/rooms/7-m.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the iridium glow of the muck in this hellhole. The walls and floors are covered with dust. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nTunnels can be found to the northwest, and southeast.%^RESET%^");
}
