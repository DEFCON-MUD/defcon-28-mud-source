inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 18-p" );
set_objects( DIR+"/monsters/newbie_ferret_2.c");
 set_exits( ([
  "west" : DIR+"/rooms/18-o.c"
  ]) );
  set_long( "This is a narrow hallway, illuminated only by the green glow of the sediment in this hellhole. The walls and floors are covered with oil. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nTunnels can be found to the west.%^RESET%^");
}
