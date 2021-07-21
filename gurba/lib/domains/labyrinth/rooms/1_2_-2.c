inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 1, 2, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Labyrinth" );
  set_long( "This is a narrow tunnel, illuminated only by the purple glow of the muck in this pit. The walls and floors are covered with dust. The smell is outright dreadful.%^RESET%^" );

  set_objects(
    DIR+"/npc/politician.c"
  );
 set_exits( ([
  "north" : DIR+"/rooms/1_1_-2.c",
  "east" : DIR+"/rooms/2_2_-2.c",
  "southeast" : DIR+"/rooms/2_3_-2.c",
  "south" : DIR+"/rooms/1_3_-2.c"
  ]) );

}

