inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/heartbleed.c.c");
 set_exits( ([
  "south" : DIR+"/rooms/2-j.c"
  ]) );
  set_long( "The floors and walls appear to be made of obsidian while the roof appears to be dripping some kind of blue liquid.  The floors and wall also appear to be covered in some kind of blood.\n\nThe dungeon continues to the south.%^RESET%^");
}
