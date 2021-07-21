inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 4-o" );
set_objects( DIR+"/monsters/average_rat_6.c");
 set_exits( ([
  "south" : DIR+"/rooms/5-o.c",
  "east" : DIR+"/rooms/4-p.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the green glow of the sediment in this area. The walls and floors are covered with blood. The air is rather stagnant.%^RESET%^\n\nThe sewer continues to the south, and east.%^RESET%^");
}
