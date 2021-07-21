inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 8, 4, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Passage" );
  set_long( "This is a narrow tunnel, illuminated only by the blue glow of the radioactive waste in this area. The walls and floors are covered with mud. The air smells like it hasn't been cycled in a while, you are getting dizzy.%^RESET%^" );

  set_objects(
    DIR+"/npc/salesdroid.c"
  );
 set_exits( ([
  "northwest" : DIR+"/rooms/7_3_-2.c",
  "northeast" : DIR+"/rooms/9_3_-2.c"
  ]) );

}

