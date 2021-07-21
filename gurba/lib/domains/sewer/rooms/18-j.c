inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 18-j" );
set_objects( DIR+"/monsters/strong_lizard_7.c");
 set_exits( ([
  "north" : DIR+"/rooms/17-j.c",
  "south" : DIR+"/rooms/19-j.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the greenish glow of the muck in this area. The walls and floors are covered with slime. The smell is outright dreadful.%^RESET%^\n\nTunnels can be found to the north, and south.%^RESET%^");
}
