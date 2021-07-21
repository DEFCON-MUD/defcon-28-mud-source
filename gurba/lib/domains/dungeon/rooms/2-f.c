inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/ms17-010.c");
 set_exits( ([
  "south" : DIR+"/rooms/3-f.c",
  "west" : DIR+"/rooms/2-e.c"
  ]) );
  set_long( "The floors and walls appear to be made of stone while the roof appears to be dripping some kind of green liquid.  The floors and wall also appear to be covered in some kind of blood.\n\nThe dungeon continues to the south, and west.%^RESET%^");
}
