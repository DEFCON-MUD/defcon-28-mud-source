inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 3-n" );
set_objects( DIR+"/monsters/strong_worm_7.c");
 set_exits( ([
  "south" : DIR+"/rooms/4-n.c",
  "east" : DIR+"/rooms/3-o.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the redish glow of the muck in this hellhole. The walls and floors are covered with oil. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nTunnels can be found to the south, and east.%^RESET%^");
}
