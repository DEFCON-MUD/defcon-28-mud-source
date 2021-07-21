inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 3-l" );
set_objects( DIR+"/monsters/newbie_ferret_2.c");
 set_exits( ([
  "north" : DIR+"/rooms/2-l.c",
  "west" : DIR+"/rooms/3-k.c"
  ]) );
  set_long( "This is a wide corridor, illuminated only by the red glow of the gunk in this hellhole. The walls and floors are covered with dust. The air is rather stagnant.%^RESET%^\n\nThe horror continues to the north, and west.%^RESET%^");
}
