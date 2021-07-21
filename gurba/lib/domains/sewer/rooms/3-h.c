inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 3-h" );
set_objects( DIR+"/monsters/uninitiated_snake_1.c");
 set_exits( ([
  "north" : DIR+"/rooms/2-h.c",
  "east" : DIR+"/rooms/3-i.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the redish glow of the sediment in this stink-pit. The walls and floors are covered with blood. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nYou may be able to find escape to the north, and east.%^RESET%^");
}
