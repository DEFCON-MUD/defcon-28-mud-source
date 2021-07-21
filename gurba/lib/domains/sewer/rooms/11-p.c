inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 11-p" );
set_objects( DIR+"/monsters/mediocre_snake_4.c");
 set_exits( ([
  "west" : DIR+"/rooms/11-o.c",
  "southeast" : DIR+"/rooms/12-q.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the orange glow of the gunk in this area. The walls and floors are covered with slime. The smell is outright dreadful.%^RESET%^\n\nThe sewer continues to the west, and southeast.%^RESET%^");
}
