inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 17-c" );
set_objects( DIR+"/monsters/sub-average_rat_5.c");
 set_exits( ([
  "northwest" : DIR+"/rooms/16-b.c",
  "southeast" : DIR+"/rooms/18-d.c"
  ]) );
  set_long( "This is a narrow corridor, illuminated only by the red glow of the muck in this area. The walls and floors are covered with blood. The smell is outright dreadful.%^RESET%^\n\nYou may be able to find escape to the northwest, and southeast.%^RESET%^");
}
