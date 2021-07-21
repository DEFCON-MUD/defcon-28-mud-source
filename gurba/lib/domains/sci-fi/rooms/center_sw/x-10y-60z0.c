inherit "/std/room";
inherit "/domains/sci-fi/lib/hallway";
#include "../../domain.h" 

void setup( void ) {
  #include "area.h"

  set_property("x", -10);
  set_property("y", -60);
  set_property("z", 0);
  add_area( "center_sw" );

  set_short(do_short());
  set_long(do_long());

 set_exits( ([
  "north" : DIR+"/rooms/center_sw/x-10y-50z0.c",
  "south" : DIR+"/rooms/center_sw/x-10y-70z0.c",
  "west" : DIR+"/rooms/center_sw/x-20y-60z0.c"
  ]) );
}
