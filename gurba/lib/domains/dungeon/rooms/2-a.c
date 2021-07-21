inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/rowhammer.c");
 set_exits( ([
  "north" : DIR+"/rooms/1-a.c",
  "southeast" : DIR+"/rooms/3-b.c"
  ]) );
  set_long( "The floors and walls appear to be made of limestone while the roof appears to be dripping some kind of blue liquid.  The floors and wall also appear to be covered in some kind of mud.\n\nThe dungeon continues to the north, and southeast.%^RESET%^");
}
