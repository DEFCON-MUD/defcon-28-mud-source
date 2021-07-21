inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 10, 8, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Hallway" );
  set_long( "This is a narrow corridor, illuminated only by the purple glow of the crappy sales material in this pit. The walls and floors are covered with dust. It smells like a hacker convention in here.%^RESET%^" );

  set_objects(
    DIR+"/npc/Gl0Rz0.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/9_8_-2.c",
  "south" : DIR+"/rooms/10_9_-2.c"
  ]) );

}

