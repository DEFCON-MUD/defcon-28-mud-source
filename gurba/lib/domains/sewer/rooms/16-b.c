inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 16-b" );
set_objects( DIR+"/monsters/meh_eel_3.c");
 set_exits( ([
  "north" : DIR+"/rooms/15-b.c",
  "southeast" : DIR+"/rooms/17-c.c"
  ]) );
  set_long( "This is a narrow hallway, illuminated only by the purple glow of the muck in this hellhole. The walls and floors are covered with dust. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nTunnels can be found to the north, and southeast.%^RESET%^");
}
