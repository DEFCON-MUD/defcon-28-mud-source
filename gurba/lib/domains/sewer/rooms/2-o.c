inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 2-o" );
set_objects( DIR+"/monsters/mediocre_ferret_4.c");
 set_exits( ([
  "east" : DIR+"/rooms/2-p.c",
  "west" : DIR+"/rooms/2-n.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the orange glow of the gunk in this area. The walls and floors are covered with oil. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe horror continues to the east, and west.%^RESET%^");
}
