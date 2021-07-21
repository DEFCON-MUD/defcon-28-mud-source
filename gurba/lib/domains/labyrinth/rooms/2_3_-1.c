inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 2, 3, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Passage" );
  set_long( "This is a cramped corridor, illuminated only by the iridium glow of the random junk evilmog thought up in this pit. The walls and floors are covered with liquid. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^" );

  set_objects(
    DIR+"/npc/droid.c"
  );
 set_exits( ([
  "east" : DIR+"/rooms/3_3_-1.c"
  ]) );

}

