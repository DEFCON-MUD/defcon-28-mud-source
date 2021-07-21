inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 15-l" );
set_objects( DIR+"/monsters/newbie_rat_2.c");
 set_exits( ([
  "east" : DIR+"/rooms/15-m.c",
  "west" : DIR+"/rooms/15-k.c",
  "northwest" : DIR+"/rooms/14-k.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the greenish glow of the muck in this stink-pit. The walls and floors are covered with liquid. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nYou may be able to find escape to the east, west, and northwest.%^RESET%^");
}
