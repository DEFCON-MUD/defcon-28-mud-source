inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 2-g" );
set_objects( DIR+"/monsters/strong_mouse_7.c");
 set_exits( ([
  "north" : DIR+"/rooms/1-g.c",
  "east" : DIR+"/rooms/2-h.c"
  ]) );
  set_long( "This is a narrow corridor, illuminated only by the orange glow of the gunk in this stink-pit. The walls and floors are covered with blood. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe sewer continues to the north, and east.%^RESET%^");
}
