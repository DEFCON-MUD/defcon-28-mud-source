inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/ms08-067.c");
 set_exits( ([
  "south" : DIR+"/rooms/2-d.c",
  "west" : DIR+"/rooms/1-c.c"
  ]) );
  set_long( "The floors and walls appear to be made of obsidian while the roof appears to be dripping some kind of purple liquid.  The floors and wall also appear to be covered in some kind of mud.\n\nThe dungeon continues to the south, and west.%^RESET%^");
}
