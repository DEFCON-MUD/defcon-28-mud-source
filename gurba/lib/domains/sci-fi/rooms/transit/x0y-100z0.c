inherit "/std/room";

#include "../../domain.h" 
void setup( void ) {

  #include "area.h"

  set_property("x", 0);
  set_property("y", -100);
  set_property("z", 0);

  add_area( "transit" );
  set_short( "Mass Transit Tube" );
  set_long( "This is a mass transit tube, you step into any of its exit points and you appear in the new destination via some science stuff, I'm not a mass transit technician so I can't tell you how this stuff works, it just does." );

 set_exits( ([
  "north" : DIR+"/rooms/transit/x0y0z0.c",
  "northwest" : DIR+"/rooms/center_sw/x-10y-90z0.c"
  ]) );
}
