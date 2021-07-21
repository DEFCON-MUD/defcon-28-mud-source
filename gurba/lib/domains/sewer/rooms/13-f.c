inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 13-f" );
set_objects( DIR+"/monsters/mediocre_ferret_4.c");
 set_exits( ([
  "north" : DIR+"/rooms/12-f.c",
  "south" : DIR+"/rooms/14-f.c",
  "west" : DIR+"/rooms/13-e.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the iridium glow of the sediment in this stink-pit. The walls and floors are covered with slime. The smell is outright dreadful.%^RESET%^\n\nYou may be able to find escape to the north, south, and west.%^RESET%^");
}
