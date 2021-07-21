inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 15-g" );
set_objects( DIR+"/monsters/meh_eel_3.c");
 set_exits( ([
  "north" : DIR+"/rooms/14-g.c",
  "south" : DIR+"/rooms/16-g.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the greenish glow of the sediment in this hellhole. The walls and floors are covered with oil. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe sewer continues to the north, and south.%^RESET%^");
}
