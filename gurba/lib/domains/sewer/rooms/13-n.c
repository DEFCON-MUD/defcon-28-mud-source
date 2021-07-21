inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 13-n" );
set_objects( DIR+"/monsters/strong_lizard_7.c");
 set_exits( ([
  "south" : DIR+"/rooms/14-n.c",
  "northeast" : DIR+"/rooms/12-o.c"
  ]) );
  set_long( "This is a wide corridor, illuminated only by the red glow of the muck in this area. The walls and floors are covered with blood. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nYou may be able to find escape to the south, and northeast.%^RESET%^");
}
