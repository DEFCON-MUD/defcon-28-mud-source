inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 4, 4, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Passage" );
  set_long( "This is a broad hallway, illuminated only by the green glow of the crud in this sty. The walls and floors are covered with oil. The air is rather stagnant.%^RESET%^" );

  set_objects(
    DIR+"/npc/banker.c"
  );
 set_exits( ([
  "southwest" : DIR+"/rooms/3_5_-1.c",
  "northwest" : DIR+"/rooms/3_3_-1.c",
  "northeast" : DIR+"/rooms/5_3_-1.c"
  ]) );

}

