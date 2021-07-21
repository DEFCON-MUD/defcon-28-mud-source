inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 11-a" );
set_objects( DIR+"/monsters/meh_mouse_3.c");
 set_exits( ([
  "north" : DIR+"/rooms/10-a.c",
  "south" : DIR+"/rooms/12-a.c"
  ]) );
  set_long( "This is a narrow corridor, illuminated only by the purple glow of the muck in this area. The walls and floors are covered with blood. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nTunnels can be found to the north, and south.%^RESET%^");
}
