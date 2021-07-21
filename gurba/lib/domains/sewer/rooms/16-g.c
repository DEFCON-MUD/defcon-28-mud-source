inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 16-g" );
set_objects( DIR+"/monsters/mediocre_alligator_4.c");
 set_exits( ([
  "north" : DIR+"/rooms/15-g.c",
  "west" : DIR+"/rooms/16-f.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the redish glow of the sediment in this area. The walls and floors are covered with oil. The smell is outright dreadful.%^RESET%^\n\nThe sewer continues to the north, and west.%^RESET%^");
}
