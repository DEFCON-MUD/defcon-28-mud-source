inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 14-o" );
set_objects( DIR+"/monsters/average_rat_6.c");
 set_exits( ([
  "east" : DIR+"/rooms/14-p.c",
  "west" : DIR+"/rooms/14-n.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the redish glow of the sediment in this area. The walls and floors are covered with liquid. The smell is outright dreadful.%^RESET%^\n\nYou may be able to find escape to the east, and west.%^RESET%^");
}
