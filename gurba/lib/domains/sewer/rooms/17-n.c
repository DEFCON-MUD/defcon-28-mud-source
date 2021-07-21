inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 17-n" );
set_objects( DIR+"/monsters/uninitiated_alligator_1.c");
 set_exits( ([
  "south" : DIR+"/rooms/18-n.c",
  "east" : DIR+"/rooms/17-o.c",
  "northwest" : DIR+"/rooms/16-m.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the greenish glow of the muck in this hellhole. The walls and floors are covered with slime. It smells like a hacker convention in here.%^RESET%^\n\nThe sewer continues to the south, east, and northwest.%^RESET%^");
}
