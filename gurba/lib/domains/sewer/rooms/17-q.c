inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 17-q" );
set_objects( DIR+"/monsters/newbie_lizard_2.c");
 set_exits( ([
  "north" : DIR+"/rooms/16-q.c",
  "west" : DIR+"/rooms/17-p.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the greenish glow of the muck in this area. The walls and floors are covered with dust. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe horror continues to the north, and west.%^RESET%^");
}
