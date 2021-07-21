inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 4-l" );
set_objects( DIR+"/monsters/sub-average_parrot_5.c");
 set_exits( ([
  "north" : DIR+"/rooms/3-l.c",
  "south" : DIR+"/rooms/5-l.c",
  "east" : DIR+"/rooms/4-m.c",
  "west" : DIR+"/rooms/4-k.c"
  ]) );
  set_long( "This is a wide corridor, illuminated only by the green glow of the muck in this hellhole. The walls and floors are covered with mud. The smell is outright dreadful.%^RESET%^\n\nThe horror continues to the north, south, east, and west.%^RESET%^");
}
