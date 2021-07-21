inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 18-f" );
set_objects( DIR+"/monsters/sub-average_eel_5.c");
 set_exits( ([
  "west" : DIR+"/rooms/18-e.c",
  "southeast" : DIR+"/rooms/19-g.c"
  ]) );
  set_long( "This is a narrow hallway, illuminated only by the green glow of the muck in this hellhole. The walls and floors are covered with oil. The smell is outright dreadful.%^RESET%^\n\nThe sewer continues to the west, and southeast.%^RESET%^");
}
