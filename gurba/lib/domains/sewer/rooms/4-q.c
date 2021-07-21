inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 4-q" );
set_objects( DIR+"/monsters/uninitiated_ferret_1.c");
 set_exits( ([
  "north" : DIR+"/rooms/3-q.c",
  "south" : DIR+"/rooms/5-q.c",
  "east" : DIR+"/rooms/4-r.c"
  ]) );
  set_long( "This is a wide hallway, illuminated only by the iridium glow of the gunk in this area. The walls and floors are covered with oil. The smell is outright dreadful.%^RESET%^\n\nThe sewer continues to the north, south, and east.%^RESET%^");
}
