inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 1-g" );
set_objects( DIR+"/monsters/meh_eel_3.c");
 set_exits( ([
  "south" : DIR+"/rooms/2-g.c",
  "east" : DIR+"/rooms/1-h.c",
  "west" : DIR+"/rooms/1-f.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the red glow of the gunk in this area. The walls and floors are covered with oil. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe horror continues to the south, east, and west.%^RESET%^");
}
