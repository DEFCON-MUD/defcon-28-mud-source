inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/dirtycow.c.c");
 set_exits( ([
  "north" : DIR+"/rooms/1-g.c",
  "south" : DIR+"/rooms/3-g.c"
  ]) );
  set_long( "The floors and walls appear to be made of stone while the roof appears to be dripping some kind of red liquid.  The floors and wall also appear to be covered in some kind of dust.\n\nThe dungeon continues to the north, and south.%^RESET%^");
}
