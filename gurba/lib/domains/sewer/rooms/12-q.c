inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 12-q" );
set_objects( DIR+"/monsters/average_ferret_6.c");
 set_exits( ([
  "north" : DIR+"/rooms/11-q.c",
  "northwest" : DIR+"/rooms/11-p.c",
  "southeast" : DIR+"/rooms/13-r.c"
  ]) );
  set_long( "This is a wide corridor, illuminated only by the orange glow of the sediment in this stink-pit. The walls and floors are covered with dust. The smell is outright dreadful.%^RESET%^\n\nThe horror continues to the north, northwest, and southeast.%^RESET%^");
}
