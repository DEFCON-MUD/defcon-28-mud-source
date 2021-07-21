inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 18-e" );
set_objects( DIR+"/monsters/sub-average_eel_5.c");
 set_exits( ([
  "east" : DIR+"/rooms/18-f.c",
  "west" : DIR+"/rooms/18-d.c"
  ]) );
  set_long( "This is a wide hallway, illuminated only by the iridium glow of the muck in this hellhole. The walls and floors are covered with mud. The air is rather stagnant.%^RESET%^\n\nThe horror continues to the east, and west.%^RESET%^");
}
