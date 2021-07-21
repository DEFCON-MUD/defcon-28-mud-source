inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 12-m" );
set_objects( DIR+"/monsters/sub-average_parrot_5.c");
 set_exits( ([
  "east" : DIR+"/rooms/12-n.c",
  "west" : DIR+"/rooms/12-l.c"
  ]) );
  set_long( "This is a cramped tunnel, illuminated only by the purple glow of the muck in this area. The walls and floors are covered with liquid. The smell is outright dreadful.%^RESET%^\n\nThe sewer continues to the east, and west.%^RESET%^");
}
