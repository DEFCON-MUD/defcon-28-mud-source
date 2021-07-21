inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 6-s" );
set_objects( DIR+"/monsters/mediocre_snake_4.c");
 set_exits( ([
  "south" : DIR+"/rooms/7-s.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the orange glow of the gunk in this hellhole. The walls and floors are covered with mud. The air is rather stagnant.%^RESET%^\n\nThe sewer continues to the south.%^RESET%^");
}
