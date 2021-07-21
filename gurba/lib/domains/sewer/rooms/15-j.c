inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 15-j" );
set_objects( DIR+"/monsters/sub-average_worm_5.c");
 set_exits( ([
  "south" : DIR+"/rooms/16-j.c",
  "southeast" : DIR+"/rooms/16-k.c"
  ]) );
  set_long( "This is a cramped tunnel, illuminated only by the green glow of the sediment in this stink-pit. The walls and floors are covered with slime. The smell is outright dreadful.%^RESET%^\n\nThe sewer continues to the south, and southeast.%^RESET%^");
}
