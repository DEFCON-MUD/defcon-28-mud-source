inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 8, 9, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Hallway" );
  set_long( "This is a broad tunnel, illuminated only by the green glow of the crap in this pit. The walls and floors are covered with slime. The air is rather stagnant.%^RESET%^" );

  set_objects(
    DIR+"/npc/droid.c"
  );
 set_exits( ([
  "southwest" : DIR+"/rooms/7_10_-1.c",
  "east" : DIR+"/rooms/9_9_-1.c"
  ]) );

}

