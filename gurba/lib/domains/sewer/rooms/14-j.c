inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 14-j" );
set_objects( DIR+"/monsters/mediocre_ferret_4.c");
 set_exits( ([
  "north" : DIR+"/rooms/13-j.c",
  "southeast" : DIR+"/rooms/15-k.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the red glow of the muck in this area. The walls and floors are covered with oil. The smell is outright dreadful.%^RESET%^\n\nThe horror continues to the north, and southeast.%^RESET%^");
}
