inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 9-b" );
set_objects( DIR+"/monsters/mediocre_lizard_4.c");
 set_exits( ([
  "east" : DIR+"/rooms/9-c.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the purple glow of the sediment in this hellhole. The walls and floors are covered with dust. The smell is outright dreadful.%^RESET%^\n\nTunnels can be found to the east.%^RESET%^");
}
