inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 8, 1, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Labyrinth" );
  set_long( "This is a narrow tunnel, illuminated only by the blue glow of the glorzo in this pit. The walls and floors are covered with dust. The smell is outright dreadful.%^RESET%^" );

  set_objects(
    DIR+"/npc/technician.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/7_1_-1.c",
  "south" : DIR+"/rooms/8_2_-1.c"
  ]) );

}

