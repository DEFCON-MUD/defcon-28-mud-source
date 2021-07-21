inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 10, 10, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Hallway" );
  set_long( "This is a cramped tunnel, illuminated only by the purple glow of the crap in this dump. The walls and floors are covered with slime. It smells like a hacker convention in here.%^RESET%^" );

  set_objects(
    DIR+"/npc/professor.c"
  );
 set_exits( ([
  "down" : DIR+"/rooms/10_10_-1.c",
  "up" : "/domains/core/rooms/sewer/x50y-10z-30.c"
  ]) );

}

