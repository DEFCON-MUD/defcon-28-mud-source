inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 17-d" );
set_objects( DIR+"/monsters/sub-average_ferret_5.c");
 set_exits( ([
  "east" : DIR+"/rooms/17-e.c",
  "northwest" : DIR+"/rooms/16-c.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the iridium glow of the sediment in this hellhole. The walls and floors are covered with blood. It smells like a hacker convention in here.%^RESET%^\n\nYou may be able to find escape to the east, and northwest.%^RESET%^");
}
