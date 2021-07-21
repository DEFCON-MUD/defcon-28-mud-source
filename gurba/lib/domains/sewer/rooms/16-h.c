inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 16-h" );
set_objects( DIR+"/monsters/uninitiated_lizard_1.c");
 set_exits( ([
  "north" : DIR+"/rooms/15-h.c",
  "south" : DIR+"/rooms/17-h.c"
  ]) );
  set_long( "This is a narrow corridor, illuminated only by the greenish glow of the muck in this area. The walls and floors are covered with dust. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe horror continues to the north, and south.%^RESET%^");
}
