inherit "/std/room";
inherit "/domains/sci-fi/lib/hallway";
#include "../../domain.h" 

void setup( void ) {
  #include "area.h"

  set_property("x", -70);
  set_property("y", -70);
  set_property("z", 0);
  add_area( "center_sw" );

  set_short(do_short());
  set_long(do_long());

 set_exits( ([
  "northwest" : DIR+"/rooms/center_sw/x-80y-60z0.c",
  "southeast" : DIR+"/rooms/center_sw/x-60y-80z0.c"
  ]) );
}
