inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 3-e" );
set_objects( DIR+"/monsters/strong_eel_7.c");
 set_exits( ([
  "northeast" : DIR+"/rooms/2-f.c",
  "southwest" : DIR+"/rooms/4-d.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the greenish glow of the muck in this stink-pit. The walls and floors are covered with slime. It smells like a hacker convention in here.%^RESET%^\n\nThe sewer continues to the northeast, and southwest.%^RESET%^");
}
