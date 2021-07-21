inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 10, 10, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Hallway" );
  set_long( "This is a wide corridor, illuminated only by the iridium glow of the sludge in this pit. The walls and floors are covered with liquid. The smell is outright dreadful.%^RESET%^" );

  set_objects(
    DIR+"/npc/teacher.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/9_10_-1.c",
  "north" : DIR+"/rooms/10_9_-1.c",
  "up" : DIR+"/rooms/10_10_0.c"
  ]) );

}

