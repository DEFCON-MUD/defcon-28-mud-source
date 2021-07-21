inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/wpad.c");
 set_exits( ([
  "north" : DIR+"/rooms/1-d.c",
  "south" : DIR+"/rooms/3-d.c",
  "northeast" : DIR+"/rooms/1-e.c"
  ]) );
  set_long( "The floors and walls appear to be made of basalt while the roof appears to be dripping some kind of orange liquid.  The floors and wall also appear to be covered in some kind of blood.\n\nThe dungeon continues to the north, south, and northeast.%^RESET%^");
}
