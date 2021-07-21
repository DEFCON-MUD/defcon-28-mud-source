inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/wpad.c");
 set_exits( ([
  "north" : DIR+"/rooms/2-c.c",
  "east" : DIR+"/rooms/3-d.c",
  "west" : DIR+"/rooms/3-b.c"
  ]) );
  set_long( "The floors and walls appear to be made of jade while the roof appears to be dripping some kind of iridium liquid.  The floors and wall also appear to be covered in some kind of mud.\n\nThe dungeon continues to the north, east, and west.%^RESET%^");
}
