inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 4-g" );
set_objects( DIR+"/monsters/uninitiated_rat_1.c");
 set_exits( ([
  "east" : DIR+"/rooms/4-h.c",
  "west" : DIR+"/rooms/4-f.c"
  ]) );
  set_long( "This is a cramped tunnel, illuminated only by the iridium glow of the sediment in this area. The walls and floors are covered with dust. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe horror continues to the east, and west.%^RESET%^");
}
