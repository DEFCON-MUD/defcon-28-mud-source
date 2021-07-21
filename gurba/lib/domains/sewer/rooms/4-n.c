inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 4-n" );
set_objects( DIR+"/monsters/meh_snake_3.c");
 set_exits( ([
  "north" : DIR+"/rooms/3-n.c",
  "southwest" : DIR+"/rooms/5-m.c"
  ]) );
  set_long( "This is a cramped tunnel, illuminated only by the green glow of the gunk in this stink-pit. The walls and floors are covered with slime. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe sewer continues to the north, and southwest.%^RESET%^");
}
