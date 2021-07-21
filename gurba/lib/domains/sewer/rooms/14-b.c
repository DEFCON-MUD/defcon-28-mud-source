inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 14-b" );
set_objects( DIR+"/monsters/newbie_lizard_2.c");
 set_exits( ([
  "north" : DIR+"/rooms/13-b.c",
  "southeast" : DIR+"/rooms/15-c.c"
  ]) );
  set_long( "This is a narrow corridor, illuminated only by the green glow of the muck in this stink-pit. The walls and floors are covered with oil. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe sewer continues to the north, and southeast.%^RESET%^");
}
