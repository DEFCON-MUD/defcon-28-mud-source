inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 18-o" );
set_objects( DIR+"/monsters/mediocre_snake_4.c");
 set_exits( ([
  "north" : DIR+"/rooms/17-o.c",
  "east" : DIR+"/rooms/18-p.c",
  "west" : DIR+"/rooms/18-n.c",
  "northeast" : DIR+"/rooms/17-p.c",
  "southwest" : DIR+"/rooms/19-n.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the greenish glow of the muck in this hellhole. The walls and floors are covered with oil. The air is rather stagnant.%^RESET%^\n\nThe sewer continues to the north, east, west, northeast, and southwest.%^RESET%^");
}
