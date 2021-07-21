inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 4, 7, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Passage" );
  set_long( "This is a cramped hallway, illuminated only by the red glow of the radioactive waste in this dump. The walls and floors are covered with blood. The air is rather stagnant.%^RESET%^" );

  set_objects(
    DIR+"/npc/analyst.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/3_7_-1.c",
  "southwest" : DIR+"/rooms/3_8_-1.c",
  "south" : DIR+"/rooms/4_8_-1.c",
  "northeast" : DIR+"/rooms/5_6_-1.c",
  "east" : DIR+"/rooms/5_7_-1.c"
  ]) );

}

