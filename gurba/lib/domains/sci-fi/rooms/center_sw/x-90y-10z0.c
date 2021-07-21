inherit "/std/room";
#include "../../domain.h" 

void setup( void ) {
  #include "area.h"

  set_property("x", -90);
  set_property("y", -10);
  set_property("z", 0);
  add_area( "center_sw" );

  set_short( "Hallway" );
  set_long( "This is a hallway, it connects the shops to the rest of the mass transit system." );

 set_exits( ([
  "south" : DIR+"/rooms/center_sw/x-90y-20z0.c",
  "east" : DIR+"/rooms/center_sw/x-80y-10z0.c",
  "northwest" : DIR+"/rooms/transit/x-100y0z0.c"
  ]) );
}
