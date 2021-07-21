inherit "/std/room";
inherit "/std/evil/advance";
#include "../../domain.h" 

void setup( void ) {
  #include "area.h"

  set_property("x", -20);
  set_property("y", -70);
  set_property("z", 0);

  add_action("do_advance", "advance");
  add_action("do_quest", "claim");
  add_action("do_quests", "quests");
  add_item("sign", do_hrsign());
  add_action("do_recast", "recast");

  add_area( "center_sw" );

  set_short( "Hallway" );
  set_long( "Welcome to the HR department, unfortunately the last of them went crazy and left. The walls are covered in fingerpaint while the bare floors have paint splotches all over.\n\nThere is a sign on the wall written in crayon." );

 set_exits( ([
  "east" : DIR+"/rooms/center_sw/x-10y-70z0.c"
  ]) );
}
