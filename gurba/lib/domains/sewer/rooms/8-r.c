inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 8-r" );
set_objects( DIR+"/monsters/sub-average_rat_5.c");
 set_exits( ([
  "east" : DIR+"/rooms/8-s.c",
  "southwest" : DIR+"/rooms/9-q.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the red glow of the gunk in this area. The walls and floors are covered with slime. The smell is outright dreadful.%^RESET%^\n\nTunnels can be found to the east, and southwest.%^RESET%^");
}
