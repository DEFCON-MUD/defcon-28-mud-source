inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 14-h" );
set_objects( DIR+"/monsters/newbie_rat_2.c");
 set_exits( ([
  "north" : DIR+"/rooms/13-h.c",
  "south" : DIR+"/rooms/15-h.c"
  ]) );
  set_long( "This is a wide hallway, illuminated only by the red glow of the gunk in this area. The walls and floors are covered with dust. The smell is outright dreadful.%^RESET%^\n\nYou may be able to find escape to the north, and south.%^RESET%^");
}
