inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/ms08-067.c");
 set_exits( ([
  "north" : DIR+"/rooms/2-d.c",
  "east" : DIR+"/rooms/3-e.c",
  "west" : DIR+"/rooms/3-c.c"
  ]) );
  set_long( "The floors and walls appear to be made of obsidian while the roof appears to be dripping some kind of purple liquid.  The floors and wall also appear to be covered in some kind of dust.\n\nThe dungeon continues to the north, east, and west.%^RESET%^");
}
