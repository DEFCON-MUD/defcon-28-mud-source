inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/ms17-010.c");
 set_exits( ([
  "south" : DIR+"/rooms/5-d.c",
  "east" : DIR+"/rooms/4-e.c"
  ]) );
  set_long( "The floors and walls appear to be made of marble while the roof appears to be dripping some kind of iridium liquid.  The floors and wall also appear to be covered in some kind of slime.\n\nThe dungeon continues to the south, and east.%^RESET%^");
}
