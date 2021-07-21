inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 15-d" );
set_objects( DIR+"/monsters/strong_lizard_7.c");
 set_exits( ([
  "south" : DIR+"/rooms/16-d.c",
  "northwest" : DIR+"/rooms/14-c.c"
  ]) );
  set_long( "This is a wide hallway, illuminated only by the orange glow of the muck in this area. The walls and floors are covered with blood. It smells like a hacker convention in here.%^RESET%^\n\nThe horror continues to the south, and northwest.%^RESET%^");
}
