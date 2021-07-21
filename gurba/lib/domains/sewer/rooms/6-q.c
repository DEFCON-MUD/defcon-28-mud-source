inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 6-q" );
set_objects( DIR+"/monsters/sub-average_parrot_5.c");
 set_exits( ([
  "north" : DIR+"/rooms/5-q.c",
  "southwest" : DIR+"/rooms/7-p.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the red glow of the muck in this hellhole. The walls and floors are covered with slime. It smells like a hacker convention in here.%^RESET%^\n\nThe sewer continues to the north, and southwest.%^RESET%^");
}
