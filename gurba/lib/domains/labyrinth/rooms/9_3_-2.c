inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 9, 3, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Labyrinth" );
  set_long( "This is a wide hallway, illuminated only by the orange glow of the crud in this pit. The walls and floors are covered with mud. It smells like a hacker convention in here.%^RESET%^" );

  set_objects(
    DIR+"/npc/professor.c"
  );
 set_exits( ([
  "southwest" : DIR+"/rooms/8_4_-2.c",
  "north" : DIR+"/rooms/9_2_-2.c",
  "southeast" : DIR+"/rooms/10_4_-2.c"
  ]) );

}

