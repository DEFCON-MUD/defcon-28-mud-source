inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 9, 2, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Passage" );
  set_long( "This is a broad corridor, illuminated only by the orange glow of the muck in this sty. The walls and floors are covered with slime. It smells like a hacker convention in here.%^RESET%^" );

  set_objects(
    DIR+"/npc/stoner.c"
  );
 set_exits( ([
  "southwest" : DIR+"/rooms/8_3_-1.c",
  "north" : DIR+"/rooms/9_1_-1.c",
  "northeast" : DIR+"/rooms/10_1_-1.c",
  "east" : DIR+"/rooms/10_2_-1.c",
  "southeast" : DIR+"/rooms/10_3_-1.c"
  ]) );

}

