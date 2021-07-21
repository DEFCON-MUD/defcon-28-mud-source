inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 8-h" );
set_objects( DIR+"/monsters/strong_worm_7.c");
 set_exits( ([
  "south" : DIR+"/rooms/9-h.c",
  "northwest" : DIR+"/rooms/7-g.c",
  "southeast" : DIR+"/rooms/9-i.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the green glow of the gunk in this area. The walls and floors are covered with mud. The air is rather stagnant.%^RESET%^\n\nYou may be able to find escape to the south, northwest, and southeast.%^RESET%^");
}
