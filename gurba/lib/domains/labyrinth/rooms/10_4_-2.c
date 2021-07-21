inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 10, 4, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Labyrinth" );
  set_long( "This is a wide tunnel, illuminated only by the iridium glow of the glorzo in this hellhole. The walls and floors are covered with mud. It smells like a combination of diesel fuel, dirt and decay.%^RESET%^" );

  set_objects(
    DIR+"/npc/analyst.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/9_4_-2.c",
  "northwest" : DIR+"/rooms/9_3_-2.c",
  "north" : DIR+"/rooms/10_3_-2.c",
  "southwest" : DIR+"/rooms/9_5_-2.c",
  "south" : DIR+"/rooms/10_5_-2.c"
  ]) );

}

