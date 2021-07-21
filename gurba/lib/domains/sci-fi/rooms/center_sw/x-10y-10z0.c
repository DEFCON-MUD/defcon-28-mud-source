inherit "/std/room";
#include "../../domain.h" 

void setup( void ) {
  #include "area.h"

  set_property("x", -10);
  set_property("y", -10);
  set_property("z", 0);
  add_area( "center_sw" );

  set_short( "Hallway" );
  set_long( "This is a standard boring hallway, the floors are some sort of nondescript washable surface, the walls look like poorly painted drywall, its almost as if somebody slapped this together in a hurry." );

 set_exits( ([
  "south" : DIR+"/rooms/center_sw/x-10y-20z0.c",
  "west" : DIR+"/rooms/center_sw/x-20y-10z0.c",
  "northeast" : DIR+"/rooms/transit/x0y0z0.c"
  ]) );
}
