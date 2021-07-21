inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 5-r" );
set_objects( DIR+"/monsters/meh_rat_3.c");
 set_exits( ([
  "north" : DIR+"/rooms/4-r.c",
  "south" : DIR+"/rooms/6-r.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the purple glow of the muck in this area. The walls and floors are covered with slime. The smell is outright dreadful.%^RESET%^\n\nYou may be able to find escape to the north, and south.%^RESET%^");
}
