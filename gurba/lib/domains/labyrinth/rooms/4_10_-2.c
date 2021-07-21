inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 4, 10, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Hallway" );
  set_long( "This is a narrow tunnel, illuminated only by the orange glow of the crap in this hellhole. The walls and floors are covered with blood. The smell.....that musty smell.....nothing else quite smells like that.....it smells like.......DEFCON.%^RESET%^" );

  set_objects(
    DIR+"/npc/droid.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/3_10_-2.c",
  "north" : DIR+"/rooms/4_9_-2.c",
  "northeast" : DIR+"/rooms/5_9_-2.c",
  "east" : DIR+"/rooms/5_10_-2.c"
  ]) );

}

