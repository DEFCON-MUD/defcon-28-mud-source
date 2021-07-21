inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 19-h" );
set_objects( DIR+"/monsters/uninitiated_lizard_1.c");
 set_exits( ([
  "east" : DIR+"/rooms/19-i.c",
  "west" : DIR+"/rooms/19-g.c",
  "northeast" : DIR+"/rooms/18-i.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the redish glow of the muck in this stink-pit. The walls and floors are covered with oil. The smell is outright dreadful.%^RESET%^\n\nThe sewer continues to the east, west, and northeast.%^RESET%^");
}
