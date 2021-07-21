inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 7, 6, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Hallway" );
  set_long( "This is a broad hallway, illuminated only by the orange glow of the crap in this pit. The walls and floors are covered with liquid. The air is rather stagnant.%^RESET%^" );

  set_objects(
    DIR+"/npc/analyst.c"
  );
 set_exits( ([
  "north" : DIR+"/rooms/7_5_-2.c",
  "south" : DIR+"/rooms/7_7_-2.c",
  "northeast" : DIR+"/rooms/8_5_-2.c"
  ]) );

}

