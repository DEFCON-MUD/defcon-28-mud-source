inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 16-c" );
set_objects( DIR+"/monsters/sub-average_mouse_5.c");
 set_exits( ([
  "north" : DIR+"/rooms/15-c.c",
  "southeast" : DIR+"/rooms/17-d.c"
  ]) );
  set_long( "This is a narrow hallway, illuminated only by the purple glow of the sediment in this stink-pit. The walls and floors are covered with oil. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe sewer continues to the north, and southeast.%^RESET%^");
}
