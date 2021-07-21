inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/ms08-067.c");
 set_exits( ([
  "east" : DIR+"/rooms/5-j.c",
  "southwest" : DIR+"/rooms/6-h.c"
  ]) );
  set_long( "The floors and walls appear to be made of basalt while the roof appears to be dripping some kind of orange liquid.  The floors and wall also appear to be covered in some kind of slime.\n\nThe dungeon continues to the east, and southwest.%^RESET%^");
}
