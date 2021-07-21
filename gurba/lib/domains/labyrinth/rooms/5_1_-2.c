inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 5, 1, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Hallway" );
  set_long( "This is a wide corridor, illuminated only by the iridium glow of the crud in this sty. The walls and floors are covered with slime. The smell is outright dreadful.%^RESET%^" );

  set_objects(
    DIR+"/npc/auditor.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/4_1_-2.c",
  "east" : DIR+"/rooms/6_1_-2.c"
  ]) );

}

