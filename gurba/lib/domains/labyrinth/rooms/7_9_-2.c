inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 7, 9, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Passage" );
  set_long( "This is a narrow corridor, illuminated only by the green glow of the crap in this sty. The walls and floors are covered with blood. The air smells like it hasn't been cycled in a while, you are getting dizzy.%^RESET%^" );

  set_objects(
    DIR+"/npc/droid.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/6_9_-2.c",
  "northwest" : DIR+"/rooms/6_8_-2.c",
  "north" : DIR+"/rooms/7_8_-2.c",
  "southeast" : DIR+"/rooms/8_10_-2.c",
  "south" : DIR+"/rooms/7_10_-2.c"
  ]) );

}

