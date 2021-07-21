inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 7-b" );
set_objects( DIR+"/monsters/average_eel_6.c");
 set_exits( ([
  "east" : DIR+"/rooms/7-c.c",
  "southeast" : DIR+"/rooms/8-c.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the purple glow of the gunk in this hellhole. The walls and floors are covered with dust. The air is rather stagnant.%^RESET%^\n\nThe horror continues to the east, and southeast.%^RESET%^");
}
