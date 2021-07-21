inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 100-r" );
set_objects( DIR+"/monsters/drown.c");
 set_exits( ([
  "up" : DIR+"/rooms/12-r.c"
  ]) );
  set_long( "This is a wide corridor, illuminated only by the iridium glow of the gunk in this stink-pit. The walls and floors are covered with slime. The smell is outright dreadful.%^RESET%^\n\nThe horror continues to the up.%^RESET%^");
}
