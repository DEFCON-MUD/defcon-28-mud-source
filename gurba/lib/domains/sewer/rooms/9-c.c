inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 9-c" );
set_objects( DIR+"/monsters/uninitiated_snake_1.c");
 set_exits( ([
  "north" : DIR+"/rooms/8-c.c",
  "west" : DIR+"/rooms/9-b.c",
  "northeast" : DIR+"/rooms/8-d.c",
  "northwest" : DIR+"/rooms/8-b.c"
  ]) );
  set_long( "This is a narrow hallway, illuminated only by the purple glow of the muck in this area. The walls and floors are covered with oil. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nYou may be able to find escape to the north, west, northeast, and northwest.%^RESET%^");
}
