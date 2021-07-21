inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 6-e" );
set_objects( DIR+"/monsters/newbie_ferret_2.c");
 set_exits( ([
  "south" : DIR+"/rooms/7-e.c",
  "east" : DIR+"/rooms/6-f.c",
  "west" : DIR+"/rooms/6-d.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the red glow of the gunk in this stink-pit. The walls and floors are covered with liquid. The air is rather stagnant.%^RESET%^\n\nThe horror continues to the south, east, and west.%^RESET%^");
}
