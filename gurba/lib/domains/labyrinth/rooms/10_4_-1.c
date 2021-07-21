inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 10, 4, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Hallway" );
  set_long( "This is a wide tunnel, illuminated only by the blue glow of the pile of GPU's that burned so bright they went radioactive in this pit. The walls and floors are covered with slime. The smell is outright dreadful.%^RESET%^" );

  set_objects(
    DIR+"/npc/goon.c"
  );
 set_exits( ([
  "northwest" : DIR+"/rooms/9_3_-1.c",
  "southwest" : DIR+"/rooms/9_5_-1.c",
  "south" : DIR+"/rooms/10_5_-1.c"
  ]) );

}

