inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 9, 7, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Passage" );
  set_long( "This is a wide tunnel, illuminated only by the iridium glow of the radioactive waste in this dump. The walls and floors are covered with liquid. To add to that, the smell here isn't exactly perfumy either.%^RESET%^" );

  set_objects(
    DIR+"/npc/analyst.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/8_7_-2.c",
  "northwest" : DIR+"/rooms/8_6_-2.c",
  "east" : DIR+"/rooms/10_7_-2.c"
  ]) );

}

