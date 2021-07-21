inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 15-o" );
set_objects( DIR+"/monsters/uninitiated_lizard_1.c");
 set_exits( ([
  "south" : DIR+"/rooms/16-o.c",
  "west" : DIR+"/rooms/15-n.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the red glow of the gunk in this area. The walls and floors are covered with liquid. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nYou may be able to find escape to the south, and west.%^RESET%^");
}
