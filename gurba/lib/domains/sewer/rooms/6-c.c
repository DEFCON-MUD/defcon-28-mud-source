inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 6-c" );
set_objects( DIR+"/monsters/average_parrot_6.c");
 set_exits( ([
  "east" : DIR+"/rooms/6-d.c",
  "west" : DIR+"/rooms/6-b.c"
  ]) );
  set_long( "This is a cramped tunnel, illuminated only by the red glow of the sediment in this area. The walls and floors are covered with blood. It smells like a hacker convention in here.%^RESET%^\n\nThe horror continues to the east, and west.%^RESET%^");
}
