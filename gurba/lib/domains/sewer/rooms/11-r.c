inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 11-r" );
set_objects( DIR+"/monsters/average_lizard_6.c");
 set_exits( ([
  "east" : DIR+"/rooms/11-s.c",
  "west" : DIR+"/rooms/11-q.c"
  ]) );
  set_long( "This is a wide corridor, illuminated only by the redish glow of the gunk in this hellhole. The walls and floors are covered with slime. The smell is outright dreadful.%^RESET%^\n\nThe sewer continues to the east, and west.%^RESET%^");
}
