inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 14-n" );
set_objects( DIR+"/monsters/strong_snake_7.c");
 set_exits( ([
  "north" : DIR+"/rooms/13-n.c",
  "east" : DIR+"/rooms/14-o.c",
  "west" : DIR+"/rooms/14-m.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the redish glow of the sediment in this area. The walls and floors are covered with mud. It smells like a hacker convention in here.%^RESET%^\n\nThe horror continues to the north, east, and west.%^RESET%^");
}
