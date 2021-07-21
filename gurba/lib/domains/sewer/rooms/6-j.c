inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 6-j" );
set_objects( DIR+"/monsters/sub-average_ferret_5.c");
 set_exits( ([
  "north" : DIR+"/rooms/5-j.c",
  "south" : DIR+"/rooms/7-j.c",
  "southwest" : DIR+"/rooms/7-i.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the red glow of the gunk in this area. The walls and floors are covered with blood. The smell is outright dreadful.%^RESET%^\n\nYou may be able to find escape to the north, south, and southwest.%^RESET%^");
}
