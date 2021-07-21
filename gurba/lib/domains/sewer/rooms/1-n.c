inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 1-n" );
set_objects( DIR+"/monsters/mediocre_snake_4.c");
 set_exits( ([
  "south" : DIR+"/rooms/2-n.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the green glow of the sediment in this hellhole. The walls and floors are covered with liquid. The smell is outright dreadful.%^RESET%^\n\nThe sewer continues to the south.%^RESET%^");
}
