inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 12-n" );
set_objects( DIR+"/monsters/newbie_ferret_2.c");
 set_exits( ([
  "west" : DIR+"/rooms/12-m.c",
  "southwest" : DIR+"/rooms/13-m.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the iridium glow of the gunk in this stink-pit. The walls and floors are covered with dust. The smell is outright dreadful.%^RESET%^\n\nYou may be able to find escape to the west, and southwest.%^RESET%^");
}
