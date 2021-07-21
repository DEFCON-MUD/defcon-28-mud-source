inherit "/std/room";
inherit "/domains/sci-fi/lib/office";
#include "../../domain.h" 

void setup( void ) {
  #include "area.h"

  set_property("x", -30);
  set_property("y", -80);
  set_property("z", 0);
  add_area( "center_sw" );

  set_short(do_short());
  set_long(do_long());

 set_exits( ([
  "south" : DIR+"/rooms/center_sw/x-30y-90z0.c"
  ]) );
}
