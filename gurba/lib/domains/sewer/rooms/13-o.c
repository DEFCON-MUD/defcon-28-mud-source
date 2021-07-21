inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 13-o" );
set_objects( DIR+"/monsters/uninitiated_alligator_1.c");
 set_exits( ([
  "north" : DIR+"/rooms/12-o.c",
  "east" : DIR+"/rooms/13-p.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the iridium glow of the gunk in this hellhole. The walls and floors are covered with blood. The smell is outright dreadful.%^RESET%^\n\nThe sewer continues to the north, and east.%^RESET%^");
}
