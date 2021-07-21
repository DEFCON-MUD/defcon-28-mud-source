inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 17-o" );
set_objects( DIR+"/monsters/strong_worm_7.c");
 set_exits( ([
  "south" : DIR+"/rooms/18-o.c",
  "west" : DIR+"/rooms/17-n.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the green glow of the gunk in this area. The walls and floors are covered with slime. The smell is outright dreadful.%^RESET%^\n\nThe horror continues to the south, and west.%^RESET%^");
}
