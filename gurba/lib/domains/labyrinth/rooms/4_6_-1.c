inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 4, 6, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Passage" );
  set_long( "This is a wide corridor, illuminated only by the green glow of the pile of put kevin back stickers in this sty. The walls and floors are covered with slime. The smell is outright dreadful.%^RESET%^" );

  set_objects(
    DIR+"/npc/professor.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/3_6_-1.c",
  "northeast" : DIR+"/rooms/5_5_-1.c"
  ]) );

}

