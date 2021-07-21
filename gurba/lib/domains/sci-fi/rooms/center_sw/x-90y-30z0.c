inherit "/std/room";
inherit "/domains/sci-fi/lib/hallway";
#include "../../domain.h" 

void setup( void ) {
  #include "area.h"

  set_property("x", -90);
  set_property("y", -30);
  set_property("z", 0);
  add_area( "center_sw" );

  set_short(do_short());
  set_long(do_long());

 set_exits( ([
  "north" : DIR+"/rooms/center_sw/x-90y-20z0.c",
  "south" : DIR+"/rooms/center_sw/x-90y-40z0.c",
  "east" : DIR+"/rooms/center_sw/x-80y-30z0.c"
  ]) );
}
