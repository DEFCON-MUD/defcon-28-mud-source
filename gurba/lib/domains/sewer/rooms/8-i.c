inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 8-i" );
set_objects( DIR+"/monsters/mediocre_snake_4.c");
 set_exits( ([
  "north" : DIR+"/rooms/7-i.c",
  "south" : DIR+"/rooms/9-i.c"
  ]) );
  set_long( "This is a narrow hallway, illuminated only by the redish glow of the muck in this hellhole. The walls and floors are covered with blood. It smells like a hacker convention in here.%^RESET%^\n\nYou may be able to find escape to the north, and south.%^RESET%^");
}
