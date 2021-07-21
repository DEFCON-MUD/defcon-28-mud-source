inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 9-i" );
set_objects( DIR+"/monsters/meh_ferret_3.c");
 set_exits( ([
  "north" : DIR+"/rooms/8-i.c",
  "northwest" : DIR+"/rooms/8-h.c",
  "southeast" : DIR+"/rooms/10-j.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the greenish glow of the sediment in this area. The walls and floors are covered with slime. It smells like a hacker convention in here.%^RESET%^\n\nYou may be able to find escape to the north, northwest, and southeast.%^RESET%^");
}
