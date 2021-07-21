inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 2-p" );
set_objects( DIR+"/monsters/average_rat_6.c");
 set_exits( ([
  "west" : DIR+"/rooms/2-o.c",
  "southeast" : DIR+"/rooms/3-q.c"
  ]) );
  set_long( "This is a wide hallway, illuminated only by the green glow of the gunk in this stink-pit. The walls and floors are covered with blood. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe horror continues to the west, and southeast.%^RESET%^");
}
