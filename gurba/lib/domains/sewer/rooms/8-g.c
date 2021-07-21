inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 8-g" );
set_objects( DIR+"/monsters/mediocre_lizard_4.c");
 set_exits( ([
  "south" : DIR+"/rooms/9-g.c",
  "northwest" : DIR+"/rooms/7-f.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the purple glow of the muck in this hellhole. The walls and floors are covered with oil. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nYou may be able to find escape to the south, and northwest.%^RESET%^");
}
