inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/dirtycow.c.c");
 set_exits( ([
  "west" : DIR+"/rooms/5-i.c",
  "southwest" : DIR+"/rooms/6-i.c"
  ]) );
  set_long( "The floors and walls appear to be made of quartz while the roof appears to be dripping some kind of iridium liquid.  The floors and wall also appear to be covered in some kind of oil.\n\nThe dungeon continues to the west, and southwest.%^RESET%^");
}
