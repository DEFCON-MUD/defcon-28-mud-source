inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 16-q" );
set_objects( DIR+"/monsters/average_parrot_6.c");
 set_exits( ([
  "south" : DIR+"/rooms/17-q.c",
  "east" : DIR+"/rooms/16-r.c"
  ]) );
  set_long( "This is a cramped tunnel, illuminated only by the red glow of the muck in this stink-pit. The walls and floors are covered with oil. It smells like a hacker convention in here.%^RESET%^\n\nThe horror continues to the south, and east.%^RESET%^");
}
