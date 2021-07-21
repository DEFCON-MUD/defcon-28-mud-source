inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 16-r" );
set_objects( DIR+"/monsters/sub-average_rat_5.c");
 set_exits( ([
  "north" : DIR+"/rooms/15-r.c",
  "west" : DIR+"/rooms/16-q.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the redish glow of the gunk in this stink-pit. The walls and floors are covered with liquid. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe horror continues to the north, and west.%^RESET%^");
}
