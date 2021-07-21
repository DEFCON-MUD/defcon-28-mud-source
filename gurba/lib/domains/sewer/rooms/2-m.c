inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 2-m" );
set_objects( DIR+"/monsters/uninitiated_rat_1.c");
 set_exits( ([
  "north" : DIR+"/rooms/1-m.c",
  "south" : DIR+"/rooms/3-m.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the redish glow of the muck in this area. The walls and floors are covered with blood. The smell is outright dreadful.%^RESET%^\n\nTunnels can be found to the north, and south.%^RESET%^");
}
