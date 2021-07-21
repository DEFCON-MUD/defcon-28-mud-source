inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 17-h" );
set_objects( DIR+"/monsters/sub-average_lizard_5.c");
 set_exits( ([
  "north" : DIR+"/rooms/16-h.c",
  "south" : DIR+"/rooms/18-h.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the redish glow of the muck in this hellhole. The walls and floors are covered with slime. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nTunnels can be found to the north, and south.%^RESET%^");
}
