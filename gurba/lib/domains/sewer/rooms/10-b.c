inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 10-b" );
set_objects( DIR+"/monsters/newbie_lizard_2.c");
 set_exits( ([
  "east" : DIR+"/rooms/10-c.c",
  "northwest" : DIR+"/rooms/9-a.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the iridium glow of the sediment in this area. The walls and floors are covered with oil. The air is rather stagnant.%^RESET%^\n\nThe sewer continues to the east, and northwest.%^RESET%^");
}
