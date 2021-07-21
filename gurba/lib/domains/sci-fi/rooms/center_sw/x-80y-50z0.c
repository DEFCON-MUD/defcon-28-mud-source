inherit "/std/room";
inherit "/domains/sci-fi/lib/hallway";
#include "../../domain.h" 

void setup( void ) {
  #include "area.h"

  set_property("x", -80);
  set_property("y", -50);
  set_property("z", 0);
  add_area( "center_sw" );

  set_short(do_short());
  set_long(do_long());

 set_exits( ([
  "south" : DIR+"/rooms/center_sw/x-80y-60z0.c",
  "northwest" : DIR+"/rooms/center_sw/x-90y-40z0.c"
  ]) );
}
