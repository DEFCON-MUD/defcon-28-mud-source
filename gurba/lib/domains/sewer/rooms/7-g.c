inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 7-g" );
set_objects( DIR+"/monsters/newbie_ferret_2.c");
 set_exits( ([
  "northwest" : DIR+"/rooms/6-f.c",
  "southeast" : DIR+"/rooms/8-h.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the red glow of the muck in this hellhole. The walls and floors are covered with liquid. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nYou may be able to find escape to the northwest, and southeast.%^RESET%^");
}
