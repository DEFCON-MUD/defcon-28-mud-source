inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 9-n" );
set_objects( DIR+"/monsters/average_eel_6.c");
 set_exits( ([
  "north" : DIR+"/rooms/8-n.c",
  "east" : DIR+"/rooms/9-o.c",
  "west" : DIR+"/rooms/9-m.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the purple glow of the sediment in this area. The walls and floors are covered with oil. The air is rather stagnant.%^RESET%^\n\nThe sewer continues to the north, east, and west.%^RESET%^");
}
