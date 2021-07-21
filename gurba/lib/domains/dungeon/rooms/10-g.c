inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/dirtycow.c.c");
 set_exits( ([
  "north" : DIR+"/rooms/9-g.c",
  "east" : DIR+"/rooms/10-h.c",
  "west" : DIR+"/rooms/10-f.c"
  ]) );
  set_long( "The floors and walls appear to be made of stone while the roof appears to be dripping some kind of orange liquid.  The floors and wall also appear to be covered in some kind of liquid.\n\nThe dungeon continues to the north, east, and west.%^RESET%^");
}
