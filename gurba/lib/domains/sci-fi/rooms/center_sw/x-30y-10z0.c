inherit "/std/room";
#include "../../domain.h" 

void setup( void ) {
  #include "area.h"

  set_property("x", -30);
  set_property("y", -10);
  set_property("z", 0);
  add_area( "center_sw" );

  set_short( "Hallway" );
  set_long( "This appears to be a hallway, there is a sign next to a door that goes south." );

  add_item("sign", "This is a rusty old sign, it has a picture of broken armour on it");
 set_exits( ([
  "south" : DIR+"/rooms/center_sw/x-30y-20z0.c",
  "east" : DIR+"/rooms/center_sw/x-20y-10z0.c",
  "west" : DIR+"/rooms/center_sw/x-40y-10z0.c"
  ]) );
}
