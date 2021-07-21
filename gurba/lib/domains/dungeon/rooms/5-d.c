inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/ms17-010.c");
 set_exits( ([
  "north" : DIR+"/rooms/4-d.c",
  "northwest" : DIR+"/rooms/4-c.c"
  ]) );
  set_long( "The floors and walls appear to be made of quartz while the roof appears to be dripping some kind of green liquid.  The floors and wall also appear to be covered in some kind of liquid.\n\nThe dungeon continues to the north, and northwest.%^RESET%^");
}
