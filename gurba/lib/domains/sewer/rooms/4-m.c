inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 4-m" );
set_objects( DIR+"/monsters/uninitiated_alligator_1.c");
 set_exits( ([
  "north" : DIR+"/rooms/3-m.c",
  "west" : DIR+"/rooms/4-l.c"
  ]) );
  set_long( "This is a narrow corridor, illuminated only by the iridium glow of the sediment in this area. The walls and floors are covered with blood. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe horror continues to the north, and west.%^RESET%^");
}
