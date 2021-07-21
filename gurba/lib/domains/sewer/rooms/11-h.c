inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 11-h" );
set_objects( DIR+"/monsters/strong_ferret_7.c");
 set_exits( ([
  "east" : DIR+"/rooms/11-i.c",
  "west" : DIR+"/rooms/11-g.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the redish glow of the sediment in this hellhole. The walls and floors are covered with dust. It smells like a hacker convention in here.%^RESET%^\n\nYou may be able to find escape to the east, and west.%^RESET%^");
}
