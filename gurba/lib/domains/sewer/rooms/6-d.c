inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 6-d" );
set_objects( DIR+"/monsters/uninitiated_ferret_1.c");
 set_exits( ([
  "north" : DIR+"/rooms/5-d.c",
  "east" : DIR+"/rooms/6-e.c",
  "west" : DIR+"/rooms/6-c.c"
  ]) );
  set_long( "This is a narrow corridor, illuminated only by the red glow of the muck in this hellhole. The walls and floors are covered with dust. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe sewer continues to the north, east, and west.%^RESET%^");
}
