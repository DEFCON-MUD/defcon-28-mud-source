inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/wpad.c");
 set_exits( ([
  "north" : DIR+"/rooms/7-f.c",
  "east" : DIR+"/rooms/8-g.c"
  ]) );
  set_long( "The floors and walls appear to be made of marble while the roof appears to be dripping some kind of iridium liquid.  The floors and wall also appear to be covered in some kind of blood.\n\nThe dungeon continues to the north, and east.%^RESET%^");
}
