inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 2-f" );
set_objects( DIR+"/monsters/average_lizard_6.c");
 set_exits( ([
  "south" : DIR+"/rooms/3-f.c",
  "southeast" : DIR+"/rooms/3-g.c",
  "southwest" : DIR+"/rooms/3-e.c"
  ]) );
  set_long( "This is a cramped tunnel, illuminated only by the redish glow of the muck in this hellhole. The walls and floors are covered with dust. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nTunnels can be found to the south, southeast, and southwest.%^RESET%^");
}
