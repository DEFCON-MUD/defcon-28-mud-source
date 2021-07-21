inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 11-l" );
set_objects( DIR+"/monsters/strong_lizard_7.c");
 set_exits( ([
  "north" : DIR+"/rooms/10-l.c",
  "east" : DIR+"/rooms/11-m.c",
  "northwest" : DIR+"/rooms/10-k.c"
  ]) );
  set_long( "This is a wide hallway, illuminated only by the green glow of the gunk in this stink-pit. The walls and floors are covered with liquid. It smells like a hacker convention in here.%^RESET%^\n\nThe horror continues to the north, east, and northwest.%^RESET%^");
}
