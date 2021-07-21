inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 5-c" );
set_objects( DIR+"/monsters/sub-average_ferret_5.c");
 set_exits( ([
  "north" : DIR+"/rooms/4-c.c",
  "northeast" : DIR+"/rooms/4-d.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the green glow of the gunk in this stink-pit. The walls and floors are covered with liquid. The smell is outright dreadful.%^RESET%^\n\nThe horror continues to the north, and northeast.%^RESET%^");
}
