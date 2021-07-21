inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 9-h" );
set_objects( DIR+"/monsters/strong_mouse_7.c");
 set_exits( ([
  "north" : DIR+"/rooms/8-h.c",
  "west" : DIR+"/rooms/9-g.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the green glow of the muck in this area. The walls and floors are covered with slime. The smell is outright dreadful.%^RESET%^\n\nYou may be able to find escape to the north, and west.%^RESET%^");
}
