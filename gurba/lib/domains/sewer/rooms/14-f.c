inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 14-f" );
set_objects( DIR+"/monsters/mediocre_snake_4.c");
 set_exits( ([
  "north" : DIR+"/rooms/13-f.c",
  "south" : DIR+"/rooms/15-f.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the greenish glow of the gunk in this hellhole. The walls and floors are covered with liquid. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe horror continues to the north, and south.%^RESET%^");
}
