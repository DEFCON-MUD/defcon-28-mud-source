inherit "/std/room";
inherit "/std/evil/sketchymining";
inherit "/domains/sci-fi/lib/mshop";
#include "../../domain.h" 

void setup( void ) {
  #include "area.h"

  set_property("x", -50);
  set_property("y", -70);
  set_property("z", 0);
  add_action("do_list", "list");

  add_action("do_upgrade", "upgrade");

  add_area( "center_sw" );

  set_short(do_short());
  set_long(do_long());

 set_exits( ([
  "south" : DIR+"/rooms/center_sw/x-50y-80z0.c"
  ]) );
}
