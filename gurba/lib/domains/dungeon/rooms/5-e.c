inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/wpad.c");
 set_exits( ([
  "south" : DIR+"/rooms/6-e.c",
  "northeast" : DIR+"/rooms/4-f.c"
  ]) );
  set_long( "The floors and walls appear to be made of basalt while the roof appears to be dripping some kind of orange liquid.  The floors and wall also appear to be covered in some kind of liquid.\n\nThe dungeon continues to the south, and northeast.%^RESET%^");
}
