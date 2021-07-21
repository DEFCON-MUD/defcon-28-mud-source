inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 3, 3, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Hallway" );
  set_long( "This is a broad hallway, illuminated only by the purple glow of the crud in this hellhole. The walls and floors are covered with mud. The air smells like it hasn't been cycled in a while, you are getting dizzy.%^RESET%^" );

  set_objects(
    DIR+"/npc/teacher.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/2_3_-1.c",
  "northwest" : DIR+"/rooms/2_2_-1.c",
  "northeast" : DIR+"/rooms/4_2_-1.c",
  "southeast" : DIR+"/rooms/4_4_-1.c"
  ]) );

}

