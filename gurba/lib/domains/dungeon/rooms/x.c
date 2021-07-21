inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 2-b" );
set_objects( DIR+"/monsters/ms17-010.c");
 set_exits( ([
  "north" : DIR+"/rooms/1-b.c",
  "south" : DIR+"/rooms/3-b.c",
  "west" : DIR+"/rooms/2-a.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the purple glow of the muck in this hellhole. The walls and floors are covered with mud. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe sewer continues to the north, south, and west.%^RESET%^");
}
