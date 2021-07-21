inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 5-g" );
set_objects( DIR+"/monsters/meh_parrot_3.c");
 set_exits( ([
  "east" : DIR+"/rooms/5-h.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the red glow of the gunk in this stink-pit. The walls and floors are covered with dust. The smell is outright dreadful.%^RESET%^\n\nThe horror continues to the east.%^RESET%^");
}
