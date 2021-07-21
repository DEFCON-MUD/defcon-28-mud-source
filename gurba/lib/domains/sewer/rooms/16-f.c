inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 16-f" );
set_objects( DIR+"/monsters/newbie_snake_2.c");
 set_exits( ([
  "east" : DIR+"/rooms/16-g.c",
  "west" : DIR+"/rooms/16-e.c"
  ]) );
  set_long( "This is a wide corridor, illuminated only by the redish glow of the muck in this area. The walls and floors are covered with blood. It smells like a hacker convention in here.%^RESET%^\n\nThe horror continues to the east, and west.%^RESET%^");
}
