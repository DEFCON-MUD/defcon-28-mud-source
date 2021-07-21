inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 9-p" );
set_objects( DIR+"/monsters/mediocre_alligator_4.c");
 set_exits( ([
  "north" : DIR+"/rooms/8-p.c",
  "east" : DIR+"/rooms/9-q.c",
  "west" : DIR+"/rooms/9-o.c",
  "northeast" : DIR+"/rooms/8-q.c"
  ]) );
  set_long( "This is a cramped tunnel, illuminated only by the iridium glow of the gunk in this stink-pit. The walls and floors are covered with blood. It smells like a hacker convention in here.%^RESET%^\n\nThe horror continues to the north, east, west, and northeast.%^RESET%^");
}
