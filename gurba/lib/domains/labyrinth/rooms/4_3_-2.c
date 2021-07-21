inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 4, 3, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Passage" );
  set_long( "This is a narrow tunnel, illuminated only by the iridium glow of the radioactive waste in this pit. The walls and floors are covered with mud. It smells like a hacker convention in here.%^RESET%^" );

  set_objects(
    DIR+"/npc/agent.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/3_3_-2.c",
  "southwest" : DIR+"/rooms/3_4_-2.c",
  "south" : DIR+"/rooms/4_4_-2.c",
  "northeast" : DIR+"/rooms/5_2_-2.c"
  ]) );

}

