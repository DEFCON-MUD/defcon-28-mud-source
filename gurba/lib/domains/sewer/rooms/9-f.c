inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 9-f" );
set_objects( DIR+"/monsters/newbie_lizard_2.c");
 set_exits( ([
  "north" : DIR+"/rooms/8-f.c",
  "east" : DIR+"/rooms/9-g.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the iridium glow of the sediment in this hellhole. The walls and floors are covered with dust. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nYou may be able to find escape to the north, and east.%^RESET%^");
}
