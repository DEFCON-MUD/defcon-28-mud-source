inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/rowhammer.c");
 set_exits( ([
  "north" : DIR+"/rooms/9-h.c",
  "east" : DIR+"/rooms/10-i.c",
  "west" : DIR+"/rooms/10-g.c"
  ]) );
  set_long( "The floors and walls appear to be made of stone while the roof appears to be dripping some kind of red liquid.  The floors and wall also appear to be covered in some kind of mud.\n\nThe dungeon continues to the north, east, and west.%^RESET%^");
}
