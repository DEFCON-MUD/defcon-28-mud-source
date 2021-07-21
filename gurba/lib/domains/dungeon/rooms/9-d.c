inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/rowhammer.c");
 set_exits( ([
  "north" : DIR+"/rooms/8-d.c",
  "south" : DIR+"/rooms/10-d.c",
  "southwest" : DIR+"/rooms/10-c.c"
  ]) );
  set_long( "The floors and walls appear to be made of jade while the roof appears to be dripping some kind of blue liquid.  The floors and wall also appear to be covered in some kind of liquid.\n\nThe dungeon continues to the north, south, and southwest.%^RESET%^");
}
