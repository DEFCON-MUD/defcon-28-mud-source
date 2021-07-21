inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 15-b" );
set_objects( DIR+"/monsters/mediocre_parrot_4.c");
 set_exits( ([
  "south" : DIR+"/rooms/16-b.c",
  "northwest" : DIR+"/rooms/14-a.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the orange glow of the muck in this stink-pit. The walls and floors are covered with mud. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nTunnels can be found to the south, and northwest.%^RESET%^");
}
