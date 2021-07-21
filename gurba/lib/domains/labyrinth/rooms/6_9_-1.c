inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 6, 9, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Passage" );
  set_long( "This is a broad hallway, illuminated only by the red glow of the crud in this sty. The walls and floors are covered with oil. The smell is outright dreadful.%^RESET%^" );

  set_objects(
    DIR+"/npc/stoner.c"
  );
 set_exits( ([
  "southwest" : DIR+"/rooms/5_10_-1.c",
  "west" : DIR+"/rooms/5_9_-1.c",
  "northeast" : DIR+"/rooms/7_8_-1.c"
  ]) );

}

