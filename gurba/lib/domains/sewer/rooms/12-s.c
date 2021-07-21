inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 12-s" );
set_objects( DIR+"/monsters/meh_eel_3.c");
 set_exits( ([
  "north" : DIR+"/rooms/11-s.c",
  "south" : DIR+"/rooms/13-s.c"
  ]) );
  set_long( "This is a wide hallway, illuminated only by the redish glow of the muck in this stink-pit. The walls and floors are covered with mud. The smell is outright dreadful.%^RESET%^\n\nYou may be able to find escape to the north, and south.%^RESET%^");
}
