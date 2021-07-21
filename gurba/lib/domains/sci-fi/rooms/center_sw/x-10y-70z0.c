inherit "/std/room";
#include "../../domain.h" 

void setup( void ) {
  #include "area.h"

  set_property("x", -10);
  set_property("y", -70);
  set_property("z", 0);
  add_area( "center_sw" );

  set_short( "hALlWAy" );
  set_long( "This is a hallway. The walls appear to be covered in fingerpaint while the floors look like they are covered in a mix of silly putty and crackers. A sign is on the wall." );

  add_item("sign", "This is a paper sign written in crayon. It says '%^HMAGENTA%^Hu%^HGREEN%^ma%^HCYAN%^n%^RESET%^ %^GREEN%^Re%^RED%^%^YELLOW%^sou%^MAGENTA%^rc%^HRED%^es%^RESET%^'");
 set_exits( ([
  "north" : DIR+"/rooms/center_sw/x-10y-60z0.c",
  "south" : DIR+"/rooms/center_sw/x-10y-80z0.c",
  "west" : DIR+"/rooms/center_sw/x-20y-70z0.c"
  ]) );
}
