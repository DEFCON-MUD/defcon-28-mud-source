inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "test" );
 set_exits( ([
  "north" : DIR+"/room/1.c",
  "south" : DIR+"/room/2.c",
  "east" : DIR+"/room/3.c"
  ]) );
  set_long( "test\n\nThe dungeon continues to the north, south, and east.%^RESET%^");
}
