inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 10-j" );
set_objects( DIR+"/monsters/meh_parrot_3.c");
 set_exits( ([
  "northeast" : DIR+"/rooms/9-k.c",
  "northwest" : DIR+"/rooms/9-i.c",
  "southeast" : DIR+"/rooms/11-k.c",
  "southwest" : DIR+"/rooms/11-i.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the iridium glow of the muck in this stink-pit. The walls and floors are covered with mud. The smell is outright dreadful.%^RESET%^\n\nThe sewer continues to the northeast, northwest, southeast, and southwest.%^RESET%^");
}
