inherit "/std/room";

#include "../include.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
 set_exits( ([
  "north" : DIR+"/rooms/1i.c",
  "south" : DIR+"/rooms/3i.c",
  "east" : DIR+"/rooms/2j.c",
  "west" : DIR+"/rooms/2h.c"
  ]) );
  set_long( "The floors and walls appear to be made of stone while the roof appears to be dripping some kind of liquid.  The floors and wall also appear to be covered in some kind of slime.\n\nThe dungeon continues to the  north, south, east, and west.%^RESET%^");
}
