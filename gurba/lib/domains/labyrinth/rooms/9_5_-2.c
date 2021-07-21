inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 9, 5, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Labyrinth" );
  set_long( "This is a cramped corridor, illuminated only by the blue glow of the pile of GPU's that burned so bright they went radioactive in this area. The walls and floors are covered with blood. The smell.....that musty smell.....nothing else quite smells like that.....it smells like.......DEFCON.%^RESET%^" );

  set_objects(
    DIR+"/npc/auditor.c"
  );
 set_exits( ([
  "southwest" : DIR+"/rooms/8_6_-2.c",
  "northeast" : DIR+"/rooms/10_4_-2.c"
  ]) );

}

