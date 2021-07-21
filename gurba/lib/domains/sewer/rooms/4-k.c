inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 4-k" );
set_objects( DIR+"/monsters/newbie_lizard_2.c");
 set_exits( ([
  "east" : DIR+"/rooms/4-l.c",
  "west" : DIR+"/rooms/4-j.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the greenish glow of the muck in this hellhole. The walls and floors are covered with oil. It smells like a hacker convention in here.%^RESET%^\n\nThe sewer continues to the east, and west.%^RESET%^");
}
