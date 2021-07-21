inherit "/std/room";
inherit "/domains/sci-fi/lib/ashop";
#include "../../domain.h" 

void setup( void ) {
  #include "area.h"

  set_property("x", -80);
  set_property("y", -30);
  set_property("z", 0);
  add_area( "center_sw" );

  set_short(do_short());
  set_long(do_long());


  set_objects( 
 DIR+"/monsters/wbot_1_20.c"
);
 set_exits( ([
  "west" : DIR+"/rooms/center_sw/x-90y-30z0.c"
  ]) );
}
