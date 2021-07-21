inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/rowhammer.c");
 set_exits( ([
  "south" : DIR+"/rooms/5-b.c",
  "east" : DIR+"/rooms/4-c.c",
  "west" : DIR+"/rooms/4-a.c",
  "southeast" : DIR+"/rooms/5-c.c"
  ]) );
  set_long( "The floors and walls appear to be made of quartz while the roof appears to be dripping some kind of orange liquid.  The floors and wall also appear to be covered in some kind of liquid.\n\nThe dungeon continues to the south, east, west, and southeast.%^RESET%^");
}
