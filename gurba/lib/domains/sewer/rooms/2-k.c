inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 2-k" );
set_objects( DIR+"/monsters/average_lizard_6.c");
 set_exits( ([
  "south" : DIR+"/rooms/3-k.c",
  "east" : DIR+"/rooms/2-l.c",
  "northwest" : DIR+"/rooms/1-j.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the purple glow of the gunk in this area. The walls and floors are covered with liquid. The air is rather stagnant.%^RESET%^\n\nYou may be able to find escape to the south, east, and northwest.%^RESET%^");
}
