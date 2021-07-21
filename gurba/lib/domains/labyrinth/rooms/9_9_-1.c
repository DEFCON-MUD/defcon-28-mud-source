inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 9, 9, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Hallway" );
  set_long( "This is a broad hallway, illuminated only by the iridium glow of the crap in this stink-pit. The walls and floors are covered with slime. It smells like a combination of diesel fuel, dirt and decay.%^RESET%^" );

  set_objects(
    DIR+"/npc/politician.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/8_9_-1.c",
  "north" : DIR+"/rooms/9_8_-1.c",
  "northeast" : DIR+"/rooms/10_8_-1.c"
  ]) );

}

