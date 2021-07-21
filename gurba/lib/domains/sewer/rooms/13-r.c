inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 13-r" );
set_objects( DIR+"/monsters/mediocre_alligator_4.c");
 set_exits( ([
  "north" : DIR+"/rooms/12-r.c",
  "west" : DIR+"/rooms/13-q.c",
  "northwest" : DIR+"/rooms/12-q.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the red glow of the sediment in this area. The walls and floors are covered with blood. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nTunnels can be found to the north, west, and northwest.%^RESET%^");
}
