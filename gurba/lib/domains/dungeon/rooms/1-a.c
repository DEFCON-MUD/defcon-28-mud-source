inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/ms08-067.c");
 set_exits( ([
  "south" : DIR+"/rooms/2-a.c",
  "east" : DIR+"/rooms/1-b.c",
  "up" : "/domains/core/rooms/sewer/x-50y80z-10.c"
  ]) );
  set_long( "The floors and walls appear to be made of obsidian while the roof appears to be dripping some kind of iridium liquid.  The floors and wall also appear to be covered in some kind of liquid.\n\nThe dungeon continues to the south, east, and up.%^RESET%^");
}
