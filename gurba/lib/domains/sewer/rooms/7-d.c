inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 7-d" );
set_objects( DIR+"/monsters/newbie_lizard_2.c");
 set_exits( ([
  "east" : DIR+"/rooms/7-e.c",
  "west" : DIR+"/rooms/7-c.c"
  ]) );
  set_long( "This is a narrow corridor, illuminated only by the redish glow of the muck in this hellhole. The walls and floors are covered with blood. It smells like a hacker convention in here.%^RESET%^\n\nThe sewer continues to the east, and west.%^RESET%^");
}
