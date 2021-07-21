inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 3-o" );
set_objects( DIR+"/monsters/meh_rat_3.c");
 set_exits( ([
  "east" : DIR+"/rooms/3-p.c",
  "west" : DIR+"/rooms/3-n.c"
  ]) );
  set_long( "This is a wide hallway, illuminated only by the purple glow of the muck in this stink-pit. The walls and floors are covered with dust. The smell is outright dreadful.%^RESET%^\n\nThe sewer continues to the east, and west.%^RESET%^");
}
