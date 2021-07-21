inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/heartbleed.c.c");
 set_exits( ([
  "north" : DIR+"/rooms/3-j.c",
  "west" : DIR+"/rooms/4-i.c"
  ]) );
  set_long( "The floors and walls appear to be made of jade while the roof appears to be dripping some kind of red liquid.  The floors and wall also appear to be covered in some kind of mud.\n\nThe dungeon continues to the north, and west.%^RESET%^");
}
