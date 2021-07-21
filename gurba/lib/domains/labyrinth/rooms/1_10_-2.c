inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 1, 10, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Labyrinth" );
  set_long( "This is a broad hallway, illuminated only by the blue glow of the crappy sales material in this stink-pit. The walls and floors are covered with mud. The air is rather stagnant.%^RESET%^" );

  set_objects(
    DIR+"/npc/salesdroid.c"
  );
 set_exits( ([
  "north" : DIR+"/rooms/1_9_-2.c",
  "northeast" : DIR+"/rooms/2_9_-2.c",
  "east" : DIR+"/rooms/2_10_-2.c"
  ]) );

}

