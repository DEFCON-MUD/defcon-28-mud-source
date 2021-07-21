inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 10-e" );
set_objects( DIR+"/monsters/uninitiated_rat_1.c");
 set_exits( ([
  "east" : DIR+"/rooms/10-f.c",
  "west" : DIR+"/rooms/10-d.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the iridium glow of the muck in this stink-pit. The walls and floors are covered with oil. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe sewer continues to the east, and west.%^RESET%^");
}
