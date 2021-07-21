inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/dirtycow.c.c");
 set_exits( ([
  "north" : DIR+"/rooms/1-j.c",
  "south" : DIR+"/rooms/3-j.c",
  "west" : DIR+"/rooms/2-i.c"
  ]) );
  set_long( "The floors and walls appear to be made of jade while the roof appears to be dripping some kind of green liquid.  The floors and wall also appear to be covered in some kind of liquid.\n\nThe dungeon continues to the north, south, and west.%^RESET%^");
}
