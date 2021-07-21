inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 1, 5, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Passage" );
  set_long( "This is a broad tunnel, illuminated only by the purple glow of the pile of GPU's that burned so bright they went radioactive in this stink-pit. The walls and floors are covered with liquid. The air is rather stagnant.%^RESET%^" );

  set_objects(
    DIR+"/npc/auditor.c"
  );
 set_exits( ([
  "north" : DIR+"/rooms/1_4_-2.c",
  "south" : DIR+"/rooms/1_6_-2.c"
  ]) );

}

