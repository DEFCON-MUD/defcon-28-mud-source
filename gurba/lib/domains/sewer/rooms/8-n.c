inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 8-n" );
set_objects( DIR+"/monsters/average_lizard_6.c");
 set_exits( ([
  "south" : DIR+"/rooms/9-n.c",
  "east" : DIR+"/rooms/8-o.c"
  ]) );
  set_long( "This is a cramped tunnel, illuminated only by the redish glow of the gunk in this hellhole. The walls and floors are covered with slime. The smell is outright dreadful.%^RESET%^\n\nThe horror continues to the south, and east.%^RESET%^");
}
