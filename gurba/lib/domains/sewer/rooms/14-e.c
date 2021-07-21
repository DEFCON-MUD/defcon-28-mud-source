inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 14-e" );
set_objects( DIR+"/monsters/newbie_alligator_2.c");
 set_exits( ([
  "north" : DIR+"/rooms/13-e.c",
  "south" : DIR+"/rooms/15-e.c"
  ]) );
  set_long( "This is a wide corridor, illuminated only by the iridium glow of the muck in this hellhole. The walls and floors are covered with mud. The smell is outright dreadful.%^RESET%^\n\nThe horror continues to the north, and south.%^RESET%^");
}
