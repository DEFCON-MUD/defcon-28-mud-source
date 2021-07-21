inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 13-m" );
set_objects( DIR+"/monsters/mediocre_alligator_4.c");
 set_exits( ([
  "south" : DIR+"/rooms/14-m.c",
  "northeast" : DIR+"/rooms/12-n.c",
  "down" : DIR+"/rooms/100-m.c"
  ]) );
  set_long( "This is a narrow corridor, illuminated only by the red glow of the muck in this stink-pit. The walls and floors are covered with liquid. The smell is outright dreadful.%^RESET%^\n\nThe sewer continues to the south, northeast, and down.%^RESET%^");
}
