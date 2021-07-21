inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 8-f" );
set_objects( DIR+"/monsters/newbie_eel_2.c");
 set_exits( ([
  "south" : DIR+"/rooms/9-f.c",
  "west" : DIR+"/rooms/8-e.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the greenish glow of the sediment in this stink-pit. The walls and floors are covered with slime. The air is rather stagnant.%^RESET%^\n\nThe sewer continues to the south, and west.%^RESET%^");
}
