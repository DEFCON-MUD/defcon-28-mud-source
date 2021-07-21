inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 11-k" );
set_objects( DIR+"/monsters/strong_ferret_7.c");
 set_exits( ([
  "northwest" : DIR+"/rooms/10-j.c",
  "southeast" : DIR+"/rooms/12-l.c"
  ]) );
  set_long( "This is a narrow hallway, illuminated only by the purple glow of the sediment in this hellhole. The walls and floors are covered with dust. It smells like a hacker convention in here.%^RESET%^\n\nThe horror continues to the northwest, and southeast.%^RESET%^");
}
