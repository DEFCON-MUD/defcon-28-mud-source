inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/rowhammer.c");
 set_exits( ([
  "south" : DIR+"/rooms/2-g.c",
  "east" : DIR+"/rooms/1-h.c",
  "west" : DIR+"/rooms/1-f.c"
  ]) );
  set_long( "The floors and walls appear to be made of marble while the roof appears to be dripping some kind of red liquid.  The floors and wall also appear to be covered in some kind of mud.\n\nThe dungeon continues to the south, east, and west.%^RESET%^");
}
