inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 15-n" );
set_objects( DIR+"/monsters/meh_mouse_3.c");
 set_exits( ([
  "east" : DIR+"/rooms/15-o.c",
  "west" : DIR+"/rooms/15-m.c"
  ]) );
  set_long( "This is a cramped tunnel, illuminated only by the red glow of the muck in this area. The walls and floors are covered with slime. It smells like a hacker convention in here.%^RESET%^\n\nThe sewer continues to the east, and west.%^RESET%^");
}
