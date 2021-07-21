inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 13-l" );
set_objects( DIR+"/monsters/sub-average_worm_5.c");
 set_exits( ([
  "north" : DIR+"/rooms/12-l.c",
  "south" : DIR+"/rooms/14-l.c"
  ]) );
  set_long( "This is a wide corridor, illuminated only by the iridium glow of the muck in this area. The walls and floors are covered with mud. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe sewer continues to the north, and south.%^RESET%^");
}
