inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 13-b" );
set_objects( DIR+"/monsters/uninitiated_eel_1.c");
 set_exits( ([
  "north" : DIR+"/rooms/12-b.c",
  "south" : DIR+"/rooms/14-b.c",
  "east" : DIR+"/rooms/13-c.c"
  ]) );
  set_long( "This is a narrow corridor, illuminated only by the redish glow of the sediment in this stink-pit. The walls and floors are covered with blood. The air is rather stagnant.%^RESET%^\n\nYou may be able to find escape to the north, south, and east.%^RESET%^");
}
