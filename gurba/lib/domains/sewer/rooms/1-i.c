inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 1-i" );
set_objects( DIR+"/monsters/meh_mouse_3.c");
 set_exits( ([
  "south" : DIR+"/rooms/2-i.c",
  "west" : DIR+"/rooms/1-h.c",
  "southeast" : DIR+"/rooms/2-j.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the orange glow of the gunk in this area. The walls and floors are covered with blood. It smells like a hacker convention in here.%^RESET%^\n\nYou may be able to find escape to the south, west, and southeast.%^RESET%^");
}
