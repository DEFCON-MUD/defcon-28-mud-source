inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 16-d" );
set_objects( DIR+"/monsters/strong_snake_7.c");
 set_exits( ([
  "north" : DIR+"/rooms/15-d.c",
  "east" : DIR+"/rooms/16-e.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the redish glow of the sediment in this area. The walls and floors are covered with blood. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nYou may be able to find escape to the north, and east.%^RESET%^");
}
