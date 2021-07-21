inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 12-p" );
set_objects( DIR+"/monsters/meh_mouse_3.c");
 set_exits( ([
  "south" : DIR+"/rooms/13-p.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the redish glow of the gunk in this area. The walls and floors are covered with dust. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe sewer continues to the south.%^RESET%^");
}
