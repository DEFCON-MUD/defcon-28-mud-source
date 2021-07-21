inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 7, 2, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Passage" );
  set_long( "This is a narrow tunnel, illuminated only by the orange glow of the pile of GPU's that burned so bright they went radioactive in this dump. The walls and floors are covered with oil. It smells like a combination of diesel fuel, dirt and decay.%^RESET%^" );

  set_objects(
    DIR+"/npc/technician.c"
  );
 set_exits( ([
  "southwest" : DIR+"/rooms/6_3_-1.c",
  "west" : DIR+"/rooms/6_2_-1.c",
  "north" : DIR+"/rooms/7_1_-1.c"
  ]) );

}

