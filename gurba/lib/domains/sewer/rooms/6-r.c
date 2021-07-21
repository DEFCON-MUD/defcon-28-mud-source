inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 6-r" );
set_objects( DIR+"/monsters/newbie_alligator_2.c");
 set_exits( ([
  "north" : DIR+"/rooms/5-r.c",
  "southeast" : DIR+"/rooms/7-s.c",
  "southwest" : DIR+"/rooms/7-q.c"
  ]) );
  set_long( "This is a wide hallway, illuminated only by the purple glow of the gunk in this stink-pit. The walls and floors are covered with oil. It smells like a hacker convention in here.%^RESET%^\n\nThe sewer continues to the north, southeast, and southwest.%^RESET%^");
}
