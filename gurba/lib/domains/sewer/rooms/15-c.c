inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 15-c" );
set_objects( DIR+"/monsters/mediocre_lizard_4.c");
 set_exits( ([
  "south" : DIR+"/rooms/16-c.c",
  "northwest" : DIR+"/rooms/14-b.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the purple glow of the sediment in this stink-pit. The walls and floors are covered with dust. It smells like a hacker convention in here.%^RESET%^\n\nThe sewer continues to the south, and northwest.%^RESET%^");
}
