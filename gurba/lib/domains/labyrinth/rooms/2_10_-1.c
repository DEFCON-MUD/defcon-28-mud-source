inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 2, 10, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Labyrinth" );
  set_long( "This is a cramped corridor, illuminated only by the orange glow of the radioactive waste in this hellhole. The walls and floors are covered with mud. It smells like a combination of diesel fuel, dirt and decay.%^RESET%^" );

  set_objects(
    DIR+"/npc/banker.c"
  );
 set_exits( ([
  "northwest" : DIR+"/rooms/1_9_-1.c",
  "west" : DIR+"/rooms/1_10_-1.c",
  "east" : DIR+"/rooms/3_10_-1.c",
  "northeast" : DIR+"/rooms/3_9_-1.c"
  ]) );

}

