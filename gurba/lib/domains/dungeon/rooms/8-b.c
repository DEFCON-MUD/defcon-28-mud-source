inherit "/std/room";
inherit "/std/evil/keytracker";

#include "../domain.h"

void setup( void ) {
  add_area( "dungeon" );
  set_short( "Dungeon" );
   add_action("do_push", "push");
   add_action("do_push", "press");
set_objects( DIR+"/monsters/heartbleed.c.c");
 set_exits( ([
  "east" : DIR+"/rooms/8-c.c",
  "west" : DIR+"/rooms/8-a.c",
  "northeast" : DIR+"/rooms/7-c.c"
  ]) );
  set_long( "The floors and walls appear to be made of basalt while the roof appears to be dripping some kind of iridium liquid.  The floors and wall also appear to be covered in some kind of mud. A button is on the wall.\n\nThe dungeon continues to the east, west, and northeast.%^RESET%^");
add_item("button", "A purple button, it says 'push me'");
}

int do_push(string arg) {
  int result;
  result = do_keytrack(7);
  return result;
}
