inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 6-k" );
set_objects( DIR+"/monsters/strong_worm_7.c");
 set_exits( ([
  "south" : DIR+"/rooms/7-k.c",
  "northwest" : DIR+"/rooms/5-j.c",
  "southeast" : DIR+"/rooms/7-l.c"
  ]) );
  set_long( "This is a narrow corridor, illuminated only by the iridium glow of the muck in this hellhole. The walls and floors are covered with dust. The smell is outright dreadful.%^RESET%^\n\nThe sewer continues to the south, northwest, and southeast.%^RESET%^");
}
