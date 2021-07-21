inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 16-p" );
set_objects( DIR+"/monsters/newbie_rat_2.c");
 set_exits( ([
  "north" : DIR+"/rooms/15-p.c",
  "south" : DIR+"/rooms/17-p.c"
  ]) );
  set_long( "This is a wide corridor, illuminated only by the greenish glow of the sediment in this area. The walls and floors are covered with liquid. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe sewer continues to the north, and south.%^RESET%^");
}
