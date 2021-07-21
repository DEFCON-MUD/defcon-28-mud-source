inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 10, 2, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Passage" );
  set_long( "This is a broad corridor, illuminated only by the orange glow of the radioactive waste in this pit. The walls and floors are covered with dust. It smells like a combination of diesel fuel, dirt and decay.%^RESET%^" );

  set_objects(
    DIR+"/npc/monkey.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/9_2_-1.c"
  ]) );

}

