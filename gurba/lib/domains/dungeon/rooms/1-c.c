inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/wpad.c");
 set_exits( ([
  "south" : DIR+"/rooms/2-c.c",
  "east" : DIR+"/rooms/1-d.c"
  ]) );
  set_long( "The floors and walls appear to be made of limestone while the roof appears to be dripping some kind of red liquid.  The floors and wall also appear to be covered in some kind of oil.\n\nThe dungeon continues to the south, and east.%^RESET%^");
}
