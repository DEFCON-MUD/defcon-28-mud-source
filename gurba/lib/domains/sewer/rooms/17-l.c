inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 17-l" );
set_objects( DIR+"/monsters/average_ferret_6.c");
 set_exits( ([
  "east" : DIR+"/rooms/17-m.c",
  "northwest" : DIR+"/rooms/16-k.c"
  ]) );
  set_long( "This is a wide corridor, illuminated only by the iridium glow of the sediment in this area. The walls and floors are covered with liquid. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe sewer continues to the east, and northwest.%^RESET%^");
}
