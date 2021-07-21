inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 11-o" );
set_objects( DIR+"/monsters/newbie_snake_2.c");
 set_exits( ([
  "east" : DIR+"/rooms/11-p.c",
  "west" : DIR+"/rooms/11-n.c"
  ]) );
  set_long( "This is a wide hallway, illuminated only by the red glow of the muck in this hellhole. The walls and floors are covered with blood. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe horror continues to the east, and west.%^RESET%^");
}
