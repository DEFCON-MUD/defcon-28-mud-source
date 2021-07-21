inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 2, 7, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Labyrinth" );
  set_long( "This is a narrow hallway, illuminated only by the blue glow of the gunk in this dump. The walls and floors are covered with liquid. The smell is outright dreadful.%^RESET%^" );

  set_objects(
    DIR+"/npc/coder.c"
  );
 set_exits( ([
  "north" : DIR+"/rooms/2_6_-1.c",
  "northeast" : DIR+"/rooms/3_6_-1.c"
  ]) );

}

