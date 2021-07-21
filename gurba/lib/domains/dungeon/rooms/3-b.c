inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/wpad.c");
 set_exits( ([
  "east" : DIR+"/rooms/3-c.c",
  "west" : DIR+"/rooms/3-a.c",
  "northwest" : DIR+"/rooms/2-a.c"
  ]) );
  set_long( "The floors and walls appear to be made of basalt while the roof appears to be dripping some kind of blue liquid.  The floors and wall also appear to be covered in some kind of slime.\n\nThe dungeon continues to the east, west, and northwest.%^RESET%^");
}
