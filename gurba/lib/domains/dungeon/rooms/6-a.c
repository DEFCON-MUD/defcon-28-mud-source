inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/wpad.c");
 set_exits( ([
  "north" : DIR+"/rooms/5-a.c",
  "southeast" : DIR+"/rooms/7-b.c"
  ]) );
  set_long( "The floors and walls appear to be made of marble while the roof appears to be dripping some kind of iridium liquid.  The floors and wall also appear to be covered in some kind of oil.\n\nThe dungeon continues to the north, and southeast.%^RESET%^");
}
