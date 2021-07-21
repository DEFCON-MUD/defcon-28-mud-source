inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 4-j" );
set_objects( DIR+"/monsters/strong_mouse_7.c");
 set_exits( ([
  "north" : DIR+"/rooms/3-j.c",
  "east" : DIR+"/rooms/4-k.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the greenish glow of the gunk in this area. The walls and floors are covered with blood. It smells like a hacker convention in here.%^RESET%^\n\nThe sewer continues to the north, and east.%^RESET%^");
}
