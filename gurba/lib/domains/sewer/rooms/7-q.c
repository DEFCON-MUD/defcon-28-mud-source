inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 7-q" );
set_objects( DIR+"/monsters/sub-average_ferret_5.c");
 set_exits( ([
  "south" : DIR+"/rooms/8-q.c",
  "northeast" : DIR+"/rooms/6-r.c"
  ]) );
  set_long( "This is a narrow corridor, illuminated only by the iridium glow of the muck in this stink-pit. The walls and floors are covered with liquid. It smells like a hacker convention in here.%^RESET%^\n\nThe horror continues to the south, and northeast.%^RESET%^");
}
