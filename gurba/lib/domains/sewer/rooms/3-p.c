inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 3-p" );
set_objects( DIR+"/monsters/newbie_ferret_2.c");
 set_exits( ([
  "south" : DIR+"/rooms/4-p.c",
  "west" : DIR+"/rooms/3-o.c"
  ]) );
  set_long( "This is a wide corridor, illuminated only by the green glow of the muck in this area. The walls and floors are covered with liquid. It smells like a hacker convention in here.%^RESET%^\n\nYou may be able to find escape to the south, and west.%^RESET%^");
}
