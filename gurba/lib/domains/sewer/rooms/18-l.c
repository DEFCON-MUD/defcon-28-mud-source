inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 18-l" );
set_objects( DIR+"/monsters/sub-average_worm_5.c");
 set_exits( ([
  "west" : DIR+"/rooms/18-k.c",
  "northwest" : DIR+"/rooms/17-k.c",
  "southeast" : DIR+"/rooms/19-m.c"
  ]) );
  set_long( "This is a narrow corridor, illuminated only by the greenish glow of the muck in this stink-pit. The walls and floors are covered with mud. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nTunnels can be found to the west, northwest, and southeast.%^RESET%^");
}
