inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 13-h" );
set_objects( DIR+"/monsters/average_lizard_6.c");
 set_exits( ([
  "north" : DIR+"/rooms/12-h.c",
  "south" : DIR+"/rooms/14-h.c",
  "east" : DIR+"/rooms/13-i.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the greenish glow of the sediment in this stink-pit. The walls and floors are covered with oil. The air is rather stagnant.%^RESET%^\n\nThe sewer continues to the north, south, and east.%^RESET%^");
}
