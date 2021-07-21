inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 5, 10, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Passage" );
  set_long( "This is a narrow tunnel, illuminated only by the orange glow of the crap in this area. The walls and floors are covered with mud. The smell is outright dreadful.%^RESET%^" );

  set_objects(
    DIR+"/npc/professor.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/4_10_-1.c",
  "northeast" : DIR+"/rooms/6_9_-1.c",
  "east" : DIR+"/rooms/6_10_-1.c"
  ]) );

}

