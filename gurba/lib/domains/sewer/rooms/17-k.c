inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 17-k" );
set_objects( DIR+"/monsters/mediocre_lizard_4.c");
 set_exits( ([
  "south" : DIR+"/rooms/18-k.c",
  "west" : DIR+"/rooms/17-j.c",
  "southeast" : DIR+"/rooms/18-l.c"
  ]) );
  set_long( "This is a wide hallway, illuminated only by the iridium glow of the muck in this hellhole. The walls and floors are covered with mud. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe horror continues to the south, west, and southeast.%^RESET%^");
}
