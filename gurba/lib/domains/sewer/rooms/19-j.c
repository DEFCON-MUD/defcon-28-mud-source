inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 19-j" );
set_objects( DIR+"/monsters/strong_snake_7.c");
 set_exits( ([
  "north" : DIR+"/rooms/18-j.c",
  "east" : DIR+"/rooms/19-k.c",
  "west" : DIR+"/rooms/19-i.c"
  ]) );
  set_long( "This is a narrow corridor, illuminated only by the red glow of the muck in this stink-pit. The walls and floors are covered with mud. The smell is outright dreadful.%^RESET%^\n\nYou may be able to find escape to the north, east, and west.%^RESET%^");
}
