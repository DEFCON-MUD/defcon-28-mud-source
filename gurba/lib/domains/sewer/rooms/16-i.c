inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 16-i" );
set_objects( DIR+"/monsters/mediocre_parrot_4.c");
 set_exits( ([
  "north" : DIR+"/rooms/15-i.c",
  "south" : DIR+"/rooms/17-i.c"
  ]) );
  set_long( "This is a wide hallway, illuminated only by the purple glow of the muck in this hellhole. The walls and floors are covered with mud. The smell is outright dreadful.%^RESET%^\n\nYou may be able to find escape to the north, and south.%^RESET%^");
}
