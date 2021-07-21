inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 14-m" );
set_objects( DIR+"/monsters/uninitiated_rat_1.c");
 set_exits( ([
  "north" : DIR+"/rooms/13-m.c",
  "east" : DIR+"/rooms/14-n.c",
  "west" : DIR+"/rooms/14-l.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the red glow of the sediment in this area. The walls and floors are covered with blood. It smells like a hacker convention in here.%^RESET%^\n\nYou may be able to find escape to the north, east, and west.%^RESET%^");
}
