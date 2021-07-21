inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 8-c" );
set_objects( DIR+"/monsters/strong_mouse_7.c");
 set_exits( ([
  "south" : DIR+"/rooms/9-c.c",
  "northwest" : DIR+"/rooms/7-b.c"
  ]) );
  set_long( "This is a narrow hallway, illuminated only by the green glow of the muck in this hellhole. The walls and floors are covered with mud. The air is rather stagnant.%^RESET%^\n\nThe sewer continues to the south, and northwest.%^RESET%^");
}
