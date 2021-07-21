inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 15-e" );
set_objects( DIR+"/monsters/mediocre_snake_4.c");
 set_exits( ([
  "north" : DIR+"/rooms/14-e.c",
  "south" : DIR+"/rooms/16-e.c",
  "east" : DIR+"/rooms/15-f.c"
  ]) );
  set_long( "This is a narrow hallway, illuminated only by the green glow of the muck in this hellhole. The walls and floors are covered with dust. It smells like a hacker convention in here.%^RESET%^\n\nThe horror continues to the north, south, and east.%^RESET%^");
}
