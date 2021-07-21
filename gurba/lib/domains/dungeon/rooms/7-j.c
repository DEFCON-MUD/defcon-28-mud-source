inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/heartbleed.c.c");
 set_exits( ([
  "north" : DIR+"/rooms/6-j.c",
  "south" : DIR+"/rooms/8-j.c",
  "west" : DIR+"/rooms/7-i.c"
  ]) );
  set_long( "The floors and walls appear to be made of marble while the roof appears to be dripping some kind of purple liquid.  The floors and wall also appear to be covered in some kind of mud.\n\nThe dungeon continues to the north, south, and west.%^RESET%^");
}
