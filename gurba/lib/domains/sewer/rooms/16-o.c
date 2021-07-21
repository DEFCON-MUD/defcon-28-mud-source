inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 16-o" );
set_objects( DIR+"/monsters/uninitiated_parrot_1.c");
 set_exits( ([
  "north" : DIR+"/rooms/15-o.c",
  "west" : DIR+"/rooms/16-n.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the greenish glow of the sediment in this hellhole. The walls and floors are covered with dust. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe sewer continues to the north, and west.%^RESET%^");
}
