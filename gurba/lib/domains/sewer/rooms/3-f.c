inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 3-f" );
set_objects( DIR+"/monsters/uninitiated_lizard_1.c");
 set_exits( ([
  "north" : DIR+"/rooms/2-f.c",
  "southwest" : DIR+"/rooms/4-e.c"
  ]) );
  set_long( "This is a wide corridor, illuminated only by the iridium glow of the muck in this area. The walls and floors are covered with oil. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nYou may be able to find escape to the north, and southwest.%^RESET%^");
}
