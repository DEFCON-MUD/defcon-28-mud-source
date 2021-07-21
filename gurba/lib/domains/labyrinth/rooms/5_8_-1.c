inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 5, 8, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Hallway" );
  set_long( "This is a narrow hallway, illuminated only by the blue glow of the gunk in this stink-pit. The walls and floors are covered with mud. The air is rather stagnant.%^RESET%^" );

  set_objects(
    DIR+"/npc/banker.c"
  );
 set_exits( ([
  "north" : DIR+"/rooms/5_7_-1.c",
  "east" : DIR+"/rooms/6_8_-1.c"
  ]) );

}

