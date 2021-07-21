inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 9-g" );
set_objects( DIR+"/monsters/meh_parrot_3.c");
 set_exits( ([
  "north" : DIR+"/rooms/8-g.c",
  "east" : DIR+"/rooms/9-h.c",
  "west" : DIR+"/rooms/9-f.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the redish glow of the sediment in this stink-pit. The walls and floors are covered with slime. It smells like a hacker convention in here.%^RESET%^\n\nTunnels can be found to the north, east, and west.%^RESET%^");
}
