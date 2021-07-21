inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/rowhammer.c");
 set_exits( ([
  "north" : DIR+"/rooms/4-g.c",
  "south" : DIR+"/rooms/6-g.c",
  "southwest" : DIR+"/rooms/6-f.c"
  ]) );
  set_long( "The floors and walls appear to be made of marble while the roof appears to be dripping some kind of green liquid.  The floors and wall also appear to be covered in some kind of slime.\n\nThe dungeon continues to the north, south, and southwest.%^RESET%^");
}
