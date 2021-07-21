inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 12-i" );
set_objects( DIR+"/monsters/newbie_snake_2.c");
 set_exits( ([
  "north" : DIR+"/rooms/11-i.c",
  "south" : DIR+"/rooms/13-i.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the iridium glow of the gunk in this hellhole. The walls and floors are covered with slime. The air is rather stagnant.%^RESET%^\n\nTunnels can be found to the north, and south.%^RESET%^");
}
