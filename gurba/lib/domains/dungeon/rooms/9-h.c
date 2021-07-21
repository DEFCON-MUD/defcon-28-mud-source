inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/heartbleed.c.c");
 set_exits( ([
  "south" : DIR+"/rooms/10-h.c",
  "northeast" : DIR+"/rooms/8-i.c",
  "down" : DIR + "/rooms/2-v.c"
  ]) );
  set_long( "The floors and walls appear to be made of basalt while the roof appears to be dripping some kind of purple liquid.  The floors and wall also appear to be covered in some kind of slime.\n\nThe dungeon continues to the south, and northeast. A hole in the ground leads down.%^RESET%^");
}
