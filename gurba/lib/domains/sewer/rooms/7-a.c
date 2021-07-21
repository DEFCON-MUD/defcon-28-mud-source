inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 7-a" );
set_objects( DIR+"/monsters/strong_lizard_7.c");
 set_exits( ([
  "north" : DIR+"/rooms/6-a.c",
  "northeast" : DIR+"/rooms/6-b.c",
  "southeast" : DIR+"/rooms/8-b.c"
  ]) );
  set_long( "This is a wide hallway, illuminated only by the orange glow of the muck in this area. The walls and floors are covered with oil. It smells like a hacker convention in here.%^RESET%^\n\nThe sewer continues to the north, northeast, and southeast.%^RESET%^");
}
