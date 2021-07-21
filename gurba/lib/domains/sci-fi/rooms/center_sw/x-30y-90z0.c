inherit "/std/room";
inherit "/domains/sci-fi/lib/hallway";
#include "../../domain.h" 

void setup( void ) {
  #include "area.h"

  set_property("x", -30);
  set_property("y", -90);
  set_property("z", 0);
  add_area( "center_sw" );

  set_short(do_short());
  set_long(do_long());

 set_exits( ([
  "north" : DIR+"/rooms/center_sw/x-30y-80z0.c",
  "east" : DIR+"/rooms/center_sw/x-20y-90z0.c",
  "west" : DIR+"/rooms/center_sw/x-40y-90z0.c"
  ]) );
}
