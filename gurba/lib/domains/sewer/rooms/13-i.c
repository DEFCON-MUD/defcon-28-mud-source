inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 13-i" );
set_objects( DIR+"/monsters/sub-average_worm_5.c");
 set_exits( ([
  "north" : DIR+"/rooms/12-i.c",
  "south" : DIR+"/rooms/14-i.c",
  "west" : DIR+"/rooms/13-h.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the purple glow of the sediment in this area. The walls and floors are covered with oil. The smell is outright dreadful.%^RESET%^\n\nThe horror continues to the north, south, and west.%^RESET%^");
}
