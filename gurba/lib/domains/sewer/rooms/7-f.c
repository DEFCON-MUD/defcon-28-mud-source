inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 7-f" );
set_objects( DIR+"/monsters/newbie_lizard_2.c");
 set_exits( ([
  "west" : DIR+"/rooms/7-e.c",
  "southeast" : DIR+"/rooms/8-g.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the iridium glow of the gunk in this area. The walls and floors are covered with dust. The smell is outright dreadful.%^RESET%^\n\nYou may be able to find escape to the west, and southeast.%^RESET%^");
}
