inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 12-e" );
set_objects( DIR+"/monsters/uninitiated_alligator_1.c");
 set_exits( ([
  "east" : DIR+"/rooms/12-f.c",
  "west" : DIR+"/rooms/12-d.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the redish glow of the sediment in this hellhole. The walls and floors are covered with liquid. It smells like a hacker convention in here.%^RESET%^\n\nYou may be able to find escape to the east, and west.%^RESET%^");
}
