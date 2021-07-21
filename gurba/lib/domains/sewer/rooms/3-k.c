inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 3-k" );
set_objects( DIR+"/monsters/average_parrot_6.c");
 set_exits( ([
  "north" : DIR+"/rooms/2-k.c",
  "east" : DIR+"/rooms/3-l.c"
  ]) );
  set_long( "This is a wide hallway, illuminated only by the redish glow of the sediment in this area. The walls and floors are covered with slime. The air is rather stagnant.%^RESET%^\n\nThe sewer continues to the north, and east.%^RESET%^");
}
