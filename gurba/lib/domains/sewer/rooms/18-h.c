inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 18-h" );
set_objects( DIR+"/monsters/meh_rat_3.c");
 set_exits( ([
  "north" : DIR+"/rooms/17-h.c",
  "west" : DIR+"/rooms/18-g.c"
  ]) );
  set_long( "This is a narrow hallway, illuminated only by the green glow of the muck in this stink-pit. The walls and floors are covered with liquid. The smell is outright dreadful.%^RESET%^\n\nThe horror continues to the north, and west.%^RESET%^");
}
