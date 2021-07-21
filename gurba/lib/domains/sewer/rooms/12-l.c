inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 12-l" );
set_objects( DIR+"/monsters/meh_rat_3.c");
 set_exits( ([
  "south" : DIR+"/rooms/13-l.c",
  "west" : DIR+"/rooms/12-k.c",
  "northwest" : DIR+"/rooms/11-k.c"
  ]) );
  set_long( "This is a cramped tunnel, illuminated only by the iridium glow of the sediment in this hellhole. The walls and floors are covered with oil. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe horror continues to the south, west, and northwest.%^RESET%^");
}
