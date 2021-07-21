inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 7-r" );
set_objects( DIR+"/monsters/uninitiated_eel_1.c");
 set_exits( ([
  "east" : DIR+"/rooms/7-s.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the greenish glow of the muck in this stink-pit. The walls and floors are covered with mud. The smell is outright dreadful.%^RESET%^\n\nThe sewer continues to the east.%^RESET%^");
}
