inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 7-p" );
set_objects( DIR+"/monsters/average_snake_6.c");
 set_exits( ([
  "west" : DIR+"/rooms/7-o.c",
  "northeast" : DIR+"/rooms/6-q.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the green glow of the muck in this stink-pit. The walls and floors are covered with slime. The smell is outright dreadful.%^RESET%^\n\nThe horror continues to the west, and northeast.%^RESET%^");
}
