inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
set_objects( DIR+"/monsters/ms08-067.c");
 set_exits( ([
  "east" : DIR+"/rooms/10-v.c",
  "west" : DIR+"/rooms/10-t.c"
  ]) );
  set_long( "The floors and walls appear to be made of quartz while the roof appears to be dripping some kind of iridium liquid.  The floors and wall also appear to be covered in some kind of dust.\n\nThe dungeon continues to the east, and west.%^RESET%^");
}
