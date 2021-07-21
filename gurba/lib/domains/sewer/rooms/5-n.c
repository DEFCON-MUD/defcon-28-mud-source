inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 5-n" );
set_objects( DIR+"/monsters/newbie_rat_2.c");
 set_exits( ([
  "south" : DIR+"/rooms/6-n.c",
  "east" : DIR+"/rooms/5-o.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the red glow of the gunk in this area. The walls and floors are covered with mud. The air is rather stagnant.%^RESET%^\n\nYou may be able to find escape to the south, and east.%^RESET%^");
}
