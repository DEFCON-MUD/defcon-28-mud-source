inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 17-i" );
set_objects( DIR+"/monsters/mediocre_ferret_4.c");
 set_exits( ([
  "north" : DIR+"/rooms/16-i.c",
  "south" : DIR+"/rooms/18-i.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the orange glow of the muck in this area. The walls and floors are covered with liquid. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe sewer continues to the north, and south.%^RESET%^");
}
