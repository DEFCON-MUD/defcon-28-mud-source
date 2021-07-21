inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 7, 6, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Hallway" );
  set_long( "This is a cramped hallway, illuminated only by the purple glow of the crap in this pit. The walls and floors are covered with slime. It smells like a hacker convention in here.%^RESET%^" );

  set_objects(
    DIR+"/npc/stoner.c"
  );
 set_exits( ([
  "north" : DIR+"/rooms/7_5_-1.c",
  "south" : DIR+"/rooms/7_7_-1.c",
  "southeast" : DIR+"/rooms/8_7_-1.c"
  ]) );

}

