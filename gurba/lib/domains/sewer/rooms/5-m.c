inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 5-m" );
set_objects( DIR+"/monsters/mediocre_parrot_4.c");
 set_exits( ([
  "south" : DIR+"/rooms/6-m.c",
  "northeast" : DIR+"/rooms/4-n.c"
  ]) );
  set_long( "This is a narrow hallway, illuminated only by the redish glow of the muck in this area. The walls and floors are covered with slime. The smell is outright dreadful.%^RESET%^\n\nTunnels can be found to the south, and northeast.%^RESET%^");
}
