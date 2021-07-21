inherit "/std/room";
inherit "/domains/sci-fi/lib/atrium";
#include "../../domain.h" 

void setup( void ) {
  #include "area.h"

  set_property("x", -30);
  set_property("y", -50);
  set_property("z", 0);
  add_area( "center_sw_atrium" );

  set_short(do_short());
  set_long(do_long());

 set_exits( ([
  "north" : DIR+"/rooms/center_sw_atrium/x-30y-40z0.c",
  "south" : DIR+"/rooms/center_sw_atrium/x-30y-60z0.c"
  ]) );
}
