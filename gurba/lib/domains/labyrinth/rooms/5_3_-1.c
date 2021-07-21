inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 5, 3, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Hallway" );
  set_long( "This is a narrow hallway, illuminated only by the purple glow of the crap in this pit. The walls and floors are covered with mud. To add to that, the smell here isn't exactly perfumy either.%^RESET%^" );

  set_objects(
    DIR+"/npc/teacher.c"
  );
 set_exits( ([
  "southwest" : DIR+"/rooms/4_4_-1.c",
  "west" : DIR+"/rooms/4_3_-1.c",
  "north" : DIR+"/rooms/5_2_-1.c",
  "east" : DIR+"/rooms/6_3_-1.c"
  ]) );

}

