inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 12-a" );
set_objects( DIR+"/monsters/sub-average_eel_5.c");
 set_exits( ([
  "north" : DIR+"/rooms/11-a.c",
  "south" : DIR+"/rooms/13-a.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the iridium glow of the muck in this hellhole. The walls and floors are covered with liquid. It smells like a hacker convention in here.%^RESET%^\n\nThe sewer continues to the north, and south.%^RESET%^");
}
