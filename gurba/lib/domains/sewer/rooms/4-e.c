inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 4-e" );
set_objects( DIR+"/monsters/uninitiated_rat_1.c");
 set_exits( ([
  "northeast" : DIR+"/rooms/3-f.c",
  "up" : "/domains/labyrinth/rooms/5_10_-3.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the red glow of the gunk in this stink-pit. The walls and floors are covered with liquid. It smells like a hacker convention in here.%^RESET%^\n\nThe horror continues to the northeast, and up.%^RESET%^");
}
