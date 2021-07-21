inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 6-n" );
set_objects( DIR+"/monsters/meh_ferret_3.c");
 set_exits( ([
  "north" : DIR+"/rooms/5-n.c",
  "west" : DIR+"/rooms/6-m.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the redish glow of the sediment in this hellhole. The walls and floors are covered with mud. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe horror continues to the north, and west.%^RESET%^");
}
