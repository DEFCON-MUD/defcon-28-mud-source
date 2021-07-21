inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 17-m" );
set_objects( DIR+"/monsters/strong_ferret_7.c");
 set_exits( ([
  "south" : DIR+"/rooms/18-m.c",
  "west" : DIR+"/rooms/17-l.c"
  ]) );
  set_long( "This is a cramped tunnel, illuminated only by the red glow of the sediment in this hellhole. The walls and floors are covered with blood. The air is rather stagnant.%^RESET%^\n\nYou may be able to find escape to the south, and west.%^RESET%^");
}
