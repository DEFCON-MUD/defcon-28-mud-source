inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 9-a" );
set_objects( DIR+"/monsters/mediocre_parrot_4.c");
 set_exits( ([
  "north" : DIR+"/rooms/8-a.c",
  "south" : DIR+"/rooms/10-a.c",
  "northeast" : DIR+"/rooms/8-b.c",
  "southeast" : DIR+"/rooms/10-b.c"
  ]) );
  set_long( "This is a wide hallway, illuminated only by the greenish glow of the muck in this hellhole. The walls and floors are covered with oil. The air is rather stagnant.%^RESET%^\n\nThe horror continues to the north, south, northeast, and southeast.%^RESET%^");
}
