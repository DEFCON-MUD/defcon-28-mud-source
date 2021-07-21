inherit "/std/room";
inherit "/std/evil/clinic";
inherit "/domains/sci-fi/lib/clinic";
#include "../../domain.h" 

void setup( void ) {
  #include "area.h"

  set_property("x", -40);
  set_property("y", -80);
  set_property("z", 0);
  add_action("do_list", "list");

  add_action("do_immune", "immune");

  add_action("do_heal", "heal");

  add_area( "center_sw" );

  set_short(do_short());
  set_long(do_long());

 set_exits( ([
  "south" : DIR+"/rooms/center_sw/x-40y-90z0.c"
  ]) );
}
