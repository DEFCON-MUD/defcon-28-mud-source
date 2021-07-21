inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 11-n" );
set_objects( DIR+"/monsters/newbie_rat_2.c");
 set_exits( ([
  "east" : DIR+"/rooms/11-o.c",
  "west" : DIR+"/rooms/11-m.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the purple glow of the sediment in this area. The walls and floors are covered with blood. The smell is outright dreadful.%^RESET%^\n\nYou may be able to find escape to the east, and west.%^RESET%^");
}
