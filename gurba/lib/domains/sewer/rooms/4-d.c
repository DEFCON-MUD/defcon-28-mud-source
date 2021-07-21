inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 4-d" );
set_objects( DIR+"/monsters/mediocre_ferret_4.c");
 set_exits( ([
  "north" : DIR+"/rooms/3-d.c",
  "northeast" : DIR+"/rooms/3-e.c",
  "southeast" : DIR+"/rooms/5-e.c",
  "southwest" : DIR+"/rooms/5-c.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the purple glow of the gunk in this stink-pit. The walls and floors are covered with slime. It smells like a hacker convention in here.%^RESET%^\n\nThe sewer continues to the north, northeast, southeast, and southwest.%^RESET%^");
}
