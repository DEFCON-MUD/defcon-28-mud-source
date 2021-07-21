inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 9-e" );
set_objects( DIR+"/monsters/meh_eel_3.c");
 set_exits( ([
  "north" : DIR+"/rooms/8-e.c",
  "west" : DIR+"/rooms/9-d.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the orange glow of the sediment in this hellhole. The walls and floors are covered with dust. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nYou may be able to find escape to the north, and west.%^RESET%^");
}
