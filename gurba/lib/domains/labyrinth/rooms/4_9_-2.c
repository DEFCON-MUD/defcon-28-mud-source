inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 4, 9, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Passage" );
  set_long( "This is a wide hallway, illuminated only by the green glow of the radioactive waste in this hellhole. The walls and floors are covered with liquid. The air is rather stagnant.%^RESET%^" );

  set_objects(
    DIR+"/npc/Gl0Rz0.c"
  );
 set_exits( ([
  "northwest" : DIR+"/rooms/3_8_-2.c",
  "south" : DIR+"/rooms/4_10_-2.c"
  ]) );

}

