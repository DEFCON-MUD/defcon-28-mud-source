inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 5, 7, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Labyrinth" );
  set_long( "This is a wide corridor, illuminated only by the red glow of the pile of put kevin back stickers in this pit. The walls and floors are covered with slime. The air is rather stagnant.%^RESET%^" );

  set_objects(
    DIR+"/npc/droid.c"
  );
 set_exits( ([
  "northeast" : DIR+"/rooms/6_6_-2.c"
  ]) );

}

