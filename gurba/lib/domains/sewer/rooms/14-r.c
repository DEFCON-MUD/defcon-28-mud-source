inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 14-r" );
set_objects( DIR+"/monsters/newbie_alligator_2.c");
 set_exits( ([
  "east" : DIR+"/rooms/14-s.c",
  "west" : DIR+"/rooms/14-q.c",
  "northeast" : DIR+"/rooms/13-s.c"
  ]) );
  set_long( "This is a wide corridor, illuminated only by the orange glow of the sediment in this hellhole. The walls and floors are covered with dust. The smell is outright dreadful.%^RESET%^\n\nThe sewer continues to the east, west, and northeast.%^RESET%^");
}
