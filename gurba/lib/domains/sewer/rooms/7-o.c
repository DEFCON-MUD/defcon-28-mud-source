inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 7-o" );
set_objects( DIR+"/monsters/strong_eel_7.c");
 set_exits( ([
  "north" : DIR+"/rooms/6-o.c",
  "east" : DIR+"/rooms/7-p.c",
  "west" : DIR+"/rooms/7-n.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the red glow of the sediment in this stink-pit. The walls and floors are covered with liquid. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe sewer continues to the north, east, and west.%^RESET%^");
}
