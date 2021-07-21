inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 19-m" );
set_objects( DIR+"/monsters/meh_eel_3.c");
 set_exits( ([
  "east" : DIR+"/rooms/19-n.c",
  "west" : DIR+"/rooms/19-l.c",
  "northwest" : DIR+"/rooms/18-l.c"
  ]) );
  set_long( "This is a narrow corridor, illuminated only by the red glow of the sediment in this area. The walls and floors are covered with liquid. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe horror continues to the east, west, and northwest.%^RESET%^");
}
