inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 18-m" );
set_objects( DIR+"/monsters/sub-average_parrot_5.c");
 set_exits( ([
  "north" : DIR+"/rooms/17-m.c",
  "east" : DIR+"/rooms/18-n.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the purple glow of the sediment in this stink-pit. The walls and floors are covered with slime. The air is rather stagnant.%^RESET%^\n\nTunnels can be found to the north, and east.%^RESET%^");
}
