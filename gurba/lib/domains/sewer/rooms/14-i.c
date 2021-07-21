inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 14-i" );
set_objects( DIR+"/monsters/mediocre_alligator_4.c");
 set_exits( ([
  "north" : DIR+"/rooms/13-i.c",
  "south" : DIR+"/rooms/15-i.c"
  ]) );
  set_long( "This is a wide hallway, illuminated only by the purple glow of the sediment in this stink-pit. The walls and floors are covered with liquid. The smell is outright dreadful.%^RESET%^\n\nThe sewer continues to the north, and south.%^RESET%^");
}
