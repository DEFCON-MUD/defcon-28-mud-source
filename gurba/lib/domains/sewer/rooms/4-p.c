inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 4-p" );
set_objects( DIR+"/monsters/uninitiated_alligator_1.c");
 set_exits( ([
  "north" : DIR+"/rooms/3-p.c",
  "south" : DIR+"/rooms/5-p.c",
  "west" : DIR+"/rooms/4-o.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the green glow of the muck in this stink-pit. The walls and floors are covered with oil. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe sewer continues to the north, south, and west.%^RESET%^");
}
