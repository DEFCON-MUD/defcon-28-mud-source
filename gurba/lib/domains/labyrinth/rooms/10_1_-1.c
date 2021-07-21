inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 10, 1, -1 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Passage" );
  set_long( "This is a narrow tunnel, illuminated only by the green glow of the pile of put kevin back stickers in this hellhole. The walls and floors are covered with liquid. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^" );

  set_objects(
    DIR+"/npc/goon.c"
  );
 set_exits( ([
  "southwest" : DIR+"/rooms/9_2_-1.c"
  ]) );

}

