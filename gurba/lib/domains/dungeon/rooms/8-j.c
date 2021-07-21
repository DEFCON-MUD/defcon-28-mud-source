inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/ms17-010.c");
 set_exits( ([
  "north" : DIR+"/rooms/7-j.c",
  "southwest" : DIR+"/rooms/9-i.c"
  ]) );
  set_long( "The floors and walls appear to be made of stone while the roof appears to be dripping some kind of red liquid.  The floors and wall also appear to be covered in some kind of slime.\n\nThe dungeon continues to the north, and southwest.%^RESET%^");
}
