inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 8, 3, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Hallway" );
  set_long( "This is a narrow hallway, illuminated only by the red glow of the crap in this pit. The walls and floors are covered with dust. It smells like a combination of diesel fuel, dirt and decay.%^RESET%^" );

  set_objects(
    DIR+"/npc/professor.c"
  );
 set_exits( ([
  "north" : DIR+"/rooms/8_2_-1.c",
  "northeast" : DIR+"/rooms/9_2_-1.c",
  "southeast" : DIR+"/rooms/9_4_-1.c"
  ]) );

}

