inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 2-h" );
set_objects( DIR+"/monsters/sub-average_worm_5.c");
 set_exits( ([
  "south" : DIR+"/rooms/3-h.c",
  "west" : DIR+"/rooms/2-g.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the green glow of the gunk in this area. The walls and floors are covered with dust. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe horror continues to the south, and west.%^RESET%^");
}
