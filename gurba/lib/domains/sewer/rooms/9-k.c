inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 9-k" );
set_objects( DIR+"/monsters/newbie_lizard_2.c");
 set_exits( ([
  "north" : DIR+"/rooms/8-k.c",
  "west" : DIR+"/rooms/9-j.c",
  "southwest" : DIR+"/rooms/10-j.c"
  ]) );
  set_long( "This is a wide hallway, illuminated only by the orange glow of the muck in this area. The walls and floors are covered with blood. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nYou may be able to find escape to the north, west, and southwest.%^RESET%^");
}
