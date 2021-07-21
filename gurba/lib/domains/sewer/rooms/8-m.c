inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 8-m" );
set_objects( DIR+"/monsters/strong_worm_7.c");
 set_exits( ([
  "south" : DIR+"/rooms/9-m.c",
  "northwest" : DIR+"/rooms/7-l.c"
  ]) );
  set_long( "This is a narrow corridor, illuminated only by the red glow of the muck in this hellhole. The walls and floors are covered with dust. It smells like a hacker convention in here.%^RESET%^\n\nThe horror continues to the south, and northwest.%^RESET%^");
}
