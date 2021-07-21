inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/wpad.c");
 set_exits( ([
  "south" : DIR+"/rooms/10-j.c",
  "west" : DIR+"/rooms/9-i.c"
  ]) );
  set_long( "The floors and walls appear to be made of stone while the roof appears to be dripping some kind of red liquid.  The floors and wall also appear to be covered in some kind of blood.\n\nThe dungeon continues to the south, and west.%^RESET%^");
}
