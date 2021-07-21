inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/heartbleed.c.c");
 set_exits( ([
  "north" : DIR+"/rooms/3-h.c",
  "east" : DIR+"/rooms/4-i.c"
  ]) );
  set_long( "The floors and walls appear to be made of basalt while the roof appears to be dripping some kind of iridium liquid.  The floors and wall also appear to be covered in some kind of blood.\n\nThe dungeon continues to the north, and east.%^RESET%^");
}
