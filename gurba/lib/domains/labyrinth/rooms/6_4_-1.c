inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 6, 4, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Hallway" );
  set_long( "This is a cramped tunnel, illuminated only by the iridium glow of the pile of GPU's that burned so bright they went radioactive in this stink-pit. The walls and floors are covered with slime. The air is rather stagnant.%^RESET%^" );

  set_objects(
    DIR+"/npc/professor.c"
  );
 set_exits( ([
  "southwest" : DIR+"/rooms/5_5_-1.c",
  "north" : DIR+"/rooms/6_3_-1.c"
  ]) );

}

