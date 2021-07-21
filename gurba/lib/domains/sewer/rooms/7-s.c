inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 7-s" );
set_objects( DIR+"/monsters/sub-average_lizard_5.c");
 set_exits( ([
  "north" : DIR+"/rooms/6-s.c",
  "south" : DIR+"/rooms/8-s.c",
  "west" : DIR+"/rooms/7-r.c",
  "northwest" : DIR+"/rooms/6-r.c"
  ]) );
  set_long( "This is a narrow corridor, illuminated only by the green glow of the sediment in this hellhole. The walls and floors are covered with mud. The air is rather stagnant.%^RESET%^\n\nThe sewer continues to the north, south, west, and northwest.%^RESET%^");
}
