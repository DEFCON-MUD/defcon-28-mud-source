inherit "/std/room";
inherit "/domains/sci-fi/lib/ashop";
#include "../../domain.h" 

void setup( void ) {
  #include "area.h"

  set_property("x", -20);
  set_property("y", -30);
  set_property("z", 0);
  add_area( "center_sw" );

  set_short(do_short());
  set_long(do_long());


  set_objects( 
 DIR+"/monsters/abot_7_8.c"
);
 set_exits( ([
  "east" : DIR+"/rooms/center_sw/x-10y-30z0.c"
  ]) );
}
