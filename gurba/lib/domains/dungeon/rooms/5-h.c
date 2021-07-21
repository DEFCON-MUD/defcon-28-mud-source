inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/wpad.c");
 set_exits( ([
  "south" : DIR+"/rooms/6-h.c"
  ]) );
  set_long( "The floors and walls appear to be made of marble while the roof appears to be dripping some kind of orange liquid.  The floors and wall also appear to be covered in some kind of dust.\n\nThe dungeon continues to the south.%^RESET%^");
}
