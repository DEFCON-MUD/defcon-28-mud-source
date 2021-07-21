inherit "/std/room";
inherit "/domains/sci-fi/lib/atrium";
#include "../../domain.h" 

void setup( void ) {
  #include "area.h"

  set_property("x", -60);
  set_property("y", -70);
  set_property("z", 0);
  add_area( "center_sw_atrium" );

  set_short(do_short());
  set_long(do_long());

 set_exits( ([
  "north" : DIR+"/rooms/center_sw_atrium/x-60y-60z0.c",
  "northwest" : DIR+"/rooms/center_sw_atrium/x-70y-60z0.c"
  ]) );
}
