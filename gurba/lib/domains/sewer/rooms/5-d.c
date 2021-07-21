inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 5-d" );
set_objects( DIR+"/monsters/newbie_lizard_2.c");
 set_exits( ([
  "south" : DIR+"/rooms/6-d.c"
  ]) );
  set_long( "This is a narrow hallway, illuminated only by the greenish glow of the muck in this area. The walls and floors are covered with slime. The air is rather stagnant.%^RESET%^\n\nThe horror continues to the south.%^RESET%^");
}
