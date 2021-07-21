inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 3, 7, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Passage" );
  set_long( "This is a cramped tunnel, illuminated only by the iridium glow of the gunk in this pit. The walls and floors are covered with mud. The air smells like it hasn't been cycled in a while, you are getting dizzy.%^RESET%^" );

  set_objects(
    DIR+"/npc/dba.c"
  );
 set_exits( ([
  "southwest" : DIR+"/rooms/2_8_-1.c",
  "south" : DIR+"/rooms/3_8_-1.c",
  "east" : DIR+"/rooms/4_7_-1.c"
  ]) );

}

