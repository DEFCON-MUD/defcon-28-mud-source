inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/ms08-067.c");
 set_exits( ([
  "south" : DIR+"/rooms/10-f.c",
  "west" : DIR+"/rooms/9-e.c",
  "northeast" : DIR+"/rooms/8-g.c"
  ]) );
  set_long( "The floors and walls appear to be made of jade while the roof appears to be dripping some kind of red liquid.  The floors and wall also appear to be covered in some kind of mud.\n\nThe dungeon continues to the south, west, and northeast.%^RESET%^");
}
