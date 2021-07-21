inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 16-e" );
set_objects( DIR+"/monsters/strong_lizard_7.c");
 set_exits( ([
  "north" : DIR+"/rooms/15-e.c",
  "east" : DIR+"/rooms/16-f.c",
  "west" : DIR+"/rooms/16-d.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the orange glow of the sediment in this stink-pit. The walls and floors are covered with oil. The smell is outright dreadful.%^RESET%^\n\nThe horror continues to the north, east, and west.%^RESET%^");
}
