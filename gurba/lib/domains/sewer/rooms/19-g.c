inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 19-g" );
set_objects( DIR+"/monsters/newbie_ferret_2.c");
 set_exits( ([
  "east" : DIR+"/rooms/19-h.c",
  "west" : DIR+"/rooms/19-f.c",
  "northwest" : DIR+"/rooms/18-f.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the iridium glow of the gunk in this hellhole. The walls and floors are covered with liquid. It smells like a hacker convention in here.%^RESET%^\n\nThe sewer continues to the east, west, and northwest.%^RESET%^");
}
