inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/rowhammer.c");
 set_exits( ([
  "south" : DIR+"/rooms/8-h.c",
  "east" : DIR+"/rooms/7-i.c",
  "northeast" : DIR+"/rooms/6-i.c"
  ]) );
  set_long( "The floors and walls appear to be made of limestone while the roof appears to be dripping some kind of purple liquid.  The floors and wall also appear to be covered in some kind of dust.\n\nThe dungeon continues to the south, east, and northeast.%^RESET%^");
}
