inherit "/std/room";

#include "../../domain.h" 
void setup( void ) {

  #include "area.h"

  set_property("x", 0);
  set_property("y", 0);
  set_property("z", 0);

  add_area( "transit" );
  set_short( "Grand Central Station" );
  set_long( "No this isn't the real grand central station, its just the central point where a series of tubes connect. The tubes send you all over the place, and there is no directory yet so you will have to figure this out on your own." );

 set_exits( ([
  "south" : DIR+"/rooms/transit/x0y-100z0.c",
  "west" : DIR+"/rooms/transit/x-100y0z0.c",
  "southwest" : DIR+"/rooms/center_sw/x-10y-10z0.c"
  ]) );
}
