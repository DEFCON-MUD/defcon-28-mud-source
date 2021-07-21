inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 8-j" );
set_objects( DIR+"/monsters/meh_snake_3.c");
 set_exits( ([
  "east" : DIR+"/rooms/8-k.c",
  "northwest" : DIR+"/rooms/7-i.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the green glow of the gunk in this stink-pit. The walls and floors are covered with slime. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe horror continues to the east, and northwest.%^RESET%^");
}
