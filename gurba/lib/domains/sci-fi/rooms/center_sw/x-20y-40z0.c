inherit "/std/room";
inherit "/domains/sci-fi/lib/ashop";
#include "../../domain.h" 

void setup( void ) {
  #include "area.h"

  set_property("x", -20);
  set_property("y", -40);
  set_property("z", 0);
  add_area( "center_sw" );

  set_short(do_short());
  set_long(do_long());


  set_objects( 
 DIR+"/monsters/abot_5_6.c"
);
 set_exits( ([
  "east" : DIR+"/rooms/center_sw/x-10y-40z0.c"
  ]) );
}
