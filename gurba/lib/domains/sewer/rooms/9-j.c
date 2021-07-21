inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 9-j" );
set_objects( DIR+"/monsters/sub-average_rat_5.c");
 set_exits( ([
  "east" : DIR+"/rooms/9-k.c",
  "down" : DIR+"/rooms/100-j.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the greenish glow of the sediment in this stink-pit. The walls and floors are covered with slime. The smell is outright dreadful.%^RESET%^\n\nThe sewer continues to the east, and down.%^RESET%^");
}
