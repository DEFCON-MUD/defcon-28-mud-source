inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 5-o" );
set_objects( DIR+"/monsters/uninitiated_alligator_1.c");
 set_exits( ([
  "north" : DIR+"/rooms/4-o.c",
  "west" : DIR+"/rooms/5-n.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the iridium glow of the sediment in this hellhole. The walls and floors are covered with dust. The smell is outright dreadful.%^RESET%^\n\nThe sewer continues to the north, and west.%^RESET%^");
}
