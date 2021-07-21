inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 9, 6, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Passage" );
  set_long( "This is a cramped corridor, illuminated only by the green glow of the muck in this stink-pit. The walls and floors are covered with dust. It smells like a hacker convention in here.%^RESET%^" );

  set_objects(
    DIR+"/npc/politician.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/8_6_-1.c",
  "northeast" : DIR+"/rooms/10_5_-1.c",
  "east" : DIR+"/rooms/10_6_-1.c",
  "southeast" : DIR+"/rooms/10_7_-1.c"
  ]) );

}

