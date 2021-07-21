inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 4-i" );
set_objects( DIR+"/monsters/mediocre_parrot_4.c");
 set_exits( ([
  "south" : DIR+"/rooms/5-i.c",
  "west" : DIR+"/rooms/4-h.c",
  "southeast" : DIR+"/rooms/5-j.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the purple glow of the muck in this area. The walls and floors are covered with blood. It smells like a hacker convention in here.%^RESET%^\n\nThe horror continues to the south, west, and southeast.%^RESET%^");
}
