inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/rowhammer.c");
 set_exits( ([
  "south" : DIR+"/rooms/7-c.c",
  "east" : DIR+"/rooms/6-d.c",
  "west" : DIR+"/rooms/6-b.c",
  "northwest" : DIR+"/rooms/5-b.c"
  ]) );
  set_long( "The floors and walls appear to be made of jade while the roof appears to be dripping some kind of purple liquid.  The floors and wall also appear to be covered in some kind of liquid.\n\nThe dungeon continues to the south, east, west, and northwest.%^RESET%^");
}
