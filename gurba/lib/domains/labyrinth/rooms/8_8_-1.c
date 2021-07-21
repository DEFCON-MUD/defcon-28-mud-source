inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 8, 8, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Passage" );
  set_long( "This is a wide tunnel, illuminated only by the blue glow of the gunk in this dump. The walls and floors are covered with slime. It smells like a hacker convention in here.%^RESET%^" );

  set_objects(
    DIR+"/npc/dba.c"
  );
 set_exits( ([
  "southwest" : DIR+"/rooms/7_9_-1.c",
  "north" : DIR+"/rooms/8_7_-1.c",
  "northeast" : DIR+"/rooms/9_7_-1.c",
  "east" : DIR+"/rooms/9_8_-1.c"
  ]) );

}

