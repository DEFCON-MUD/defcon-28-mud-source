inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/dirtycow.c.c");
 set_exits( ([
  "east" : DIR+"/rooms/8-h.c",
  "west" : DIR+"/rooms/8-f.c",
  "southwest" : DIR+"/rooms/9-f.c"
  ]) );
  set_long( "The floors and walls appear to be made of obsidian while the roof appears to be dripping some kind of iridium liquid.  The floors and wall also appear to be covered in some kind of oil.\n\nThe dungeon continues to the east, west, and southwest.%^RESET%^");
}
