inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/ms08-067.c");
 set_exits( ([
  "north" : DIR+"/rooms/1-i.c",
  "south" : DIR+"/rooms/3-i.c",
  "east" : DIR+"/rooms/2-j.c",
  "west" : DIR+"/rooms/2-h.c"
  ]) );
  set_long( "The floors and walls appear to be made of basalt while the roof appears to be dripping some kind of green liquid.  The floors and wall also appear to be covered in some kind of blood.\n\nThe dungeon continues to the north, south, east, and west.%^RESET%^");
}
