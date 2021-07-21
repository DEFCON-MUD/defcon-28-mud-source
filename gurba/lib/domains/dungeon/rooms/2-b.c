inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/dirtycow.c.c");
 set_exits( ([
  "north" : DIR+"/rooms/1-b.c",
  "east" : DIR+"/rooms/2-c.c"
  ]) );
  set_long( "The floors and walls appear to be made of basalt while the roof appears to be dripping some kind of blue liquid.  The floors and wall also appear to be covered in some kind of liquid.\n\nThe dungeon continues to the north, and east.%^RESET%^");
}
