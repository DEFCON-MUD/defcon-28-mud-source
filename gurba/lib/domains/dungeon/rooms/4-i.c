inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/ms17-010.c");
 set_exits( ([
  "east" : DIR+"/rooms/4-j.c",
  "west" : DIR+"/rooms/4-h.c"
  ]) );
  set_long( "The floors and walls appear to be made of quartz while the roof appears to be dripping some kind of orange liquid.  The floors and wall also appear to be covered in some kind of mud.\n\nThe dungeon continues to the east, and west.%^RESET%^");
}
