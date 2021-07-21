inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 7-i" );
set_objects( DIR+"/monsters/strong_snake_7.c");
 set_exits( ([
  "south" : DIR+"/rooms/8-i.c",
  "west" : DIR+"/rooms/7-h.c",
  "northeast" : DIR+"/rooms/6-j.c",
  "southeast" : DIR+"/rooms/8-j.c"
  ]) );
  set_long( "This is a wide corridor, illuminated only by the greenish glow of the sediment in this hellhole. The walls and floors are covered with slime. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nTunnels can be found to the south, west, northeast, and southeast.%^RESET%^");
}
