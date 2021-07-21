inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 8-d" );
set_objects( DIR+"/monsters/mediocre_snake_4.c");
 set_exits( ([
  "south" : DIR+"/rooms/9-d.c",
  "southwest" : DIR+"/rooms/9-c.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the orange glow of the gunk in this hellhole. The walls and floors are covered with liquid. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nYou may be able to find escape to the south, and southwest.%^RESET%^");
}
