inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 1-l" );
set_objects( DIR+"/monsters/average_snake_6.c");
 set_exits( ([
  "east" : DIR+"/rooms/1-m.c",
  "west" : DIR+"/rooms/1-k.c"
  ]) );
  set_long( "This is a wide corridor, illuminated only by the red glow of the gunk in this stink-pit. The walls and floors are covered with liquid. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe horror continues to the east, and west.%^RESET%^");
}
