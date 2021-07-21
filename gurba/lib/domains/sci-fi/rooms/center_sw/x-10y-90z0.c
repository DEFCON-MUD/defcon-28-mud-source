inherit "/std/room";
inherit "/domains/sci-fi/lib/hallway";
#include "../../domain.h" 

void setup( void ) {
  #include "area.h"

  set_property("x", -10);
  set_property("y", -90);
  set_property("z", 0);
  add_area( "center_sw" );

  set_short(do_short());
  set_long(do_long());

 set_exits( ([
  "north" : DIR+"/rooms/center_sw/x-10y-80z0.c",
  "west" : DIR+"/rooms/center_sw/x-20y-90z0.c",
  "southeast" : DIR+"/rooms/transit/x0y-100z0.c"
  ]) );
}
