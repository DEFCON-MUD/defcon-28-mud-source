inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 14-g" );
set_objects( DIR+"/monsters/meh_mouse_3.c");
 set_exits( ([
  "north" : DIR+"/rooms/13-g.c",
  "south" : DIR+"/rooms/15-g.c"
  ]) );
  set_long( "This is a narrow hallway, illuminated only by the orange glow of the muck in this stink-pit. The walls and floors are covered with slime. It smells like a hacker convention in here.%^RESET%^\n\nThe sewer continues to the north, and south.%^RESET%^");
}
