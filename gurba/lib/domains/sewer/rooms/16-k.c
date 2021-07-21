inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 16-k" );
set_objects( DIR+"/monsters/meh_ferret_3.c");
 set_exits( ([
  "northwest" : DIR+"/rooms/15-j.c",
  "southeast" : DIR+"/rooms/17-l.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the green glow of the muck in this stink-pit. The walls and floors are covered with mud. It smells like a hacker convention in here.%^RESET%^\n\nYou may be able to find escape to the northwest, and southeast.%^RESET%^");
}
