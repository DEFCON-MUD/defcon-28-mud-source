inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 17-p" );
set_objects( DIR+"/monsters/meh_ferret_3.c");
 set_exits( ([
  "north" : DIR+"/rooms/16-p.c",
  "east" : DIR+"/rooms/17-q.c",
  "southwest" : DIR+"/rooms/18-o.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the purple glow of the sediment in this stink-pit. The walls and floors are covered with slime. It smells like a hacker convention in here.%^RESET%^\n\nThe sewer continues to the north, east, and southwest.%^RESET%^");
}
