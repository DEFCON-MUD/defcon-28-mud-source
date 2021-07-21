inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 11-f" );
set_objects( DIR+"/monsters/newbie_eel_2.c");
 set_exits( ([
  "east" : DIR+"/rooms/11-g.c",
  "west" : DIR+"/rooms/11-e.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the purple glow of the sediment in this stink-pit. The walls and floors are covered with dust. The air is rather stagnant.%^RESET%^\n\nThe sewer continues to the east, and west.%^RESET%^");
}
