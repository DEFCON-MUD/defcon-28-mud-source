inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/ms08-067.c");
 set_exits( ([
  "north" : DIR+"/rooms/9-f.c",
  "east" : DIR+"/rooms/10-g.c"
  ]) );
  set_long( "The floors and walls appear to be made of marble while the roof appears to be dripping some kind of red liquid.  The floors and wall also appear to be covered in some kind of dust.\n\nThe dungeon continues to the north, and east.%^RESET%^");
}
