inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 13-k" );
set_objects( DIR+"/monsters/newbie_eel_2.c");
 set_exits( ([
  "north" : DIR+"/rooms/12-k.c",
  "south" : DIR+"/rooms/14-k.c"
  ]) );
  set_long( "This is a wide hallway, illuminated only by the iridium glow of the sediment in this area. The walls and floors are covered with mud. The smell is outright dreadful.%^RESET%^\n\nTunnels can be found to the north, and south.%^RESET%^");
}
