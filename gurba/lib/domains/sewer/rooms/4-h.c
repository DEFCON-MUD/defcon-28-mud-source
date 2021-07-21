inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 4-h" );
set_objects( DIR+"/monsters/sub-average_ferret_5.c");
 set_exits( ([
  "east" : DIR+"/rooms/4-i.c",
  "west" : DIR+"/rooms/4-g.c",
  "northwest" : DIR+"/rooms/3-g.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the greenish glow of the sediment in this hellhole. The walls and floors are covered with slime. It smells like a hacker convention in here.%^RESET%^\n\nThe sewer continues to the east, west, and northwest.%^RESET%^");
}
