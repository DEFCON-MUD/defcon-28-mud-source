inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/wpad.c");
 set_exits( ([
  "north" : DIR+"/rooms/6-b.c",
  "northwest" : DIR+"/rooms/6-a.c"
  ]) );
  set_long( "The floors and walls appear to be made of obsidian while the roof appears to be dripping some kind of blue liquid.  The floors and wall also appear to be covered in some kind of liquid.\n\nThe dungeon continues to the north, and northwest.%^RESET%^");
}
