inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 3, 4, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Passage" );
  set_long( "This is a wide corridor, illuminated only by the blue glow of the radioactive waste in this stink-pit. The walls and floors are covered with oil. The smell is outright dreadful.%^RESET%^" );

  set_objects(
    DIR+"/npc/technician.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/2_4_-1.c",
  "down" : DIR+"/rooms/4_4_-2.c"
  ]) );

}

