inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 6-g" );
set_objects( DIR+"/monsters/mediocre_parrot_4.c");
 set_exits( ([
  "east" : DIR+"/rooms/6-h.c",
  "northwest" : DIR+"/rooms/5-f.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the redish glow of the gunk in this stink-pit. The walls and floors are covered with blood. The air is rather stagnant.%^RESET%^\n\nYou may be able to find escape to the east, and northwest.%^RESET%^");
}
