inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 9-d" );
set_objects( DIR+"/monsters/uninitiated_eel_1.c");
 set_exits( ([
  "north" : DIR+"/rooms/8-d.c",
  "east" : DIR+"/rooms/9-e.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the red glow of the gunk in this area. The walls and floors are covered with liquid. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nYou may be able to find escape to the north, and east.%^RESET%^");
}
