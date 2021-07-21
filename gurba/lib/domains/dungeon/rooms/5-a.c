inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/rowhammer.c");
 set_exits( ([
  "south" : DIR+"/rooms/6-a.c",
  "east" : DIR+"/rooms/5-b.c"
  ]) );
  set_long( "The floors and walls appear to be made of stone while the roof appears to be dripping some kind of blue liquid.  The floors and wall also appear to be covered in some kind of blood.\n\nThe dungeon continues to the south, and east.%^RESET%^");
}
