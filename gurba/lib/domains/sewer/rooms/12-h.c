inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 12-h" );
set_objects( DIR+"/monsters/uninitiated_snake_1.c");
 set_exits( ([
  "south" : DIR+"/rooms/13-h.c",
  "west" : DIR+"/rooms/12-g.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the purple glow of the gunk in this hellhole. The walls and floors are covered with mud. It smells like a hacker convention in here.%^RESET%^\n\nThe sewer continues to the south, and west.%^RESET%^");
}
