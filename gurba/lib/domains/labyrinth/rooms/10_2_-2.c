inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 10, 2, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Hallway" );
  set_long( "This is a narrow tunnel, illuminated only by the blue glow of the muck in this hellhole. The walls and floors are covered with liquid. The air is rather stagnant.%^RESET%^" );

  set_objects(
    DIR+"/npc/Gl0Rz0.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/9_2_-2.c",
  "north" : DIR+"/rooms/10_1_-2.c"
  ]) );

}

