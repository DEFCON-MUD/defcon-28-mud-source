inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 5-k" );
set_objects( DIR+"/monsters/average_ferret_6.c");
 set_exits( ([
  "east" : DIR+"/rooms/5-l.c",
  "southeast" : DIR+"/rooms/6-l.c"
  ]) );
  set_long( "This is a narrow hallway, illuminated only by the redish glow of the sediment in this stink-pit. The walls and floors are covered with slime. The smell is outright dreadful.%^RESET%^\n\nThe horror continues to the east, and southeast.%^RESET%^");
}
