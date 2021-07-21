inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 15-i" );
set_objects( DIR+"/monsters/newbie_ferret_2.c");
 set_exits( ([
  "north" : DIR+"/rooms/14-i.c",
  "south" : DIR+"/rooms/16-i.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the red glow of the sediment in this stink-pit. The walls and floors are covered with dust. The air is rather stagnant.%^RESET%^\n\nThe sewer continues to the north, and south.%^RESET%^");
}
