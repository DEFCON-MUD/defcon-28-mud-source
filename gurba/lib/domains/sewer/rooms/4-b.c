inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 4-b" );
set_objects( DIR+"/monsters/mediocre_snake_4.c");
 set_exits( ([
  "south" : DIR+"/rooms/5-b.c",
  "northeast" : DIR+"/rooms/3-c.c"
  ]) );
  set_long( "This is a wide corridor, illuminated only by the iridium glow of the muck in this stink-pit. The walls and floors are covered with liquid. It smells like a hacker convention in here.%^RESET%^\n\nThe horror continues to the south, and northeast.%^RESET%^");
}
