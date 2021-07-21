inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 17-g" );
set_objects( DIR+"/monsters/mediocre_ferret_4.c");
 set_exits( ([
  "south" : DIR+"/rooms/18-g.c",
  "west" : DIR+"/rooms/17-f.c"
  ]) );
  set_long( "This is a cramped tunnel, illuminated only by the iridium glow of the muck in this area. The walls and floors are covered with liquid. It smells like a hacker convention in here.%^RESET%^\n\nThe sewer continues to the south, and west.%^RESET%^");
}
