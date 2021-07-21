inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 12-k" );
set_objects( DIR+"/monsters/strong_lizard_7.c");
 set_exits( ([
  "south" : DIR+"/rooms/13-k.c",
  "east" : DIR+"/rooms/12-l.c",
  "northwest" : DIR+"/rooms/11-j.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the iridium glow of the gunk in this hellhole. The walls and floors are covered with mud. The smell is outright dreadful.%^RESET%^\n\nThe sewer continues to the south, east, and northwest.%^RESET%^");
}
