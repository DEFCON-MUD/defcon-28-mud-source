inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 2, 5, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Labyrinth" );
  set_long( "This is a wide tunnel, illuminated only by the blue glow of the sludge in this area. The walls and floors are covered with mud. The smell is outright dreadful.%^RESET%^" );

  set_objects(
    DIR+"/npc/droid.c"
  );
 set_exits( ([
  "southwest" : DIR+"/rooms/1_6_-2.c",
  "north" : DIR+"/rooms/2_4_-2.c",
  "northeast" : DIR+"/rooms/3_4_-2.c",
  "east" : DIR+"/rooms/3_5_-2.c"
  ]) );

}

