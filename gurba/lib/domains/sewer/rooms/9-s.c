inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 9-s" );
set_objects( DIR+"/monsters/uninitiated_ferret_1.c");
 set_exits( ([
  "west" : DIR+"/rooms/9-r.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the redish glow of the muck in this area. The walls and floors are covered with oil. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nYou may be able to find escape to the west.%^RESET%^");
}
