inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 4, 4, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Labyrinth" );
  set_long( "This is a narrow tunnel, illuminated only by the green glow of the glorzo in this stink-pit. The walls and floors are covered with blood. The air is rather stagnant.%^RESET%^" );

  set_objects(
    DIR+"/npc/professor.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/3_4_-2.c",
  "north" : DIR+"/rooms/4_3_-2.c",
  "south" : DIR+"/rooms/4_5_-2.c"
  ]) );

}

