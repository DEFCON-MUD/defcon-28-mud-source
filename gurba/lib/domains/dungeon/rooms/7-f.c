inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/rowhammer.c");
 set_exits( ([
  "south" : DIR+"/rooms/8-f.c",
  "east" : DIR+"/rooms/7-g.c"
  ]) );
  set_long( "The floors and walls appear to be made of basalt while the roof appears to be dripping some kind of purple liquid.  The floors and wall also appear to be covered in some kind of oil.\n\nThe dungeon continues to the south, and east.%^RESET%^");
}
