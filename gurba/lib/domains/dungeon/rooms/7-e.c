inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/wpad.c");
 set_exits( ([
  "south" : DIR+"/rooms/8-e.c",
  "west" : DIR+"/rooms/7-d.c"
  ]) );
  set_long( "The floors and walls appear to be made of basalt while the roof appears to be dripping some kind of green liquid.  The floors and wall also appear to be covered in some kind of oil.\n\nThe dungeon continues to the south, and west.%^RESET%^");
}
