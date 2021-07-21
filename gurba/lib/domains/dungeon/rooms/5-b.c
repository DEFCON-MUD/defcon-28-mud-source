inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/heartbleed.c.c");
 set_exits( ([
  "north" : DIR+"/rooms/4-b.c",
  "west" : DIR+"/rooms/5-a.c",
  "southeast" : DIR+"/rooms/6-c.c"
  ]) );
  set_long( "The floors and walls appear to be made of basalt while the roof appears to be dripping some kind of purple liquid.  The floors and wall also appear to be covered in some kind of liquid.\n\nThe dungeon continues to the north, west, and southeast.%^RESET%^");
}
