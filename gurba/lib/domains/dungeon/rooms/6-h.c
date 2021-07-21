inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/dirtycow.c.c");
 set_exits( ([
  "north" : DIR+"/rooms/5-h.c",
  "west" : DIR+"/rooms/6-g.c",
  "northeast" : DIR+"/rooms/5-i.c"
  ]) );
  set_long( "The floors and walls appear to be made of basalt while the roof appears to be dripping some kind of red liquid.  The floors and wall also appear to be covered in some kind of slime.\n\nThe dungeon continues to the north, west, and northeast.%^RESET%^");
}
