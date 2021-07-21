inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/rowhammer.c");
 set_exits( ([
  "east" : DIR+"/rooms/5-d.c",
  "northwest" : DIR+"/rooms/4-b.c"
  ]) );
  set_long( "The floors and walls appear to be made of marble while the roof appears to be dripping some kind of green liquid.  The floors and wall also appear to be covered in some kind of dust.\n\nThe dungeon continues to the east, and northwest.%^RESET%^");
}
