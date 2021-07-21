inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 5, 6, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Hallway" );
  set_long( "This is a wide hallway, illuminated only by the blue glow of the muck in this sty. The walls and floors are covered with slime. It smells like a hacker convention in here.%^RESET%^" );

  set_objects(
    DIR+"/npc/goon.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/4_6_-2.c",
  "north" : DIR+"/rooms/5_5_-2.c",
  "northwest" : DIR+"/rooms/4_5_-2.c"
  ]) );

}

