inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 1-k" );
set_objects( DIR+"/monsters/meh_eel_3.c");
 set_exits( ([
  "east" : DIR+"/rooms/1-l.c",
  "west" : DIR+"/rooms/1-j.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the iridium glow of the sediment in this stink-pit. The walls and floors are covered with blood. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nYou may be able to find escape to the east, and west.%^RESET%^");
}
