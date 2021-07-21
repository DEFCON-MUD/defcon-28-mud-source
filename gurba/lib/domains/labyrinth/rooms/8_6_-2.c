inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 8, 6, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Passage" );
  set_long( "This is a broad tunnel, illuminated only by the red glow of the sludge in this area. The walls and floors are covered with blood. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^" );

  set_objects(
    DIR+"/npc/droid.c"
  );
 set_exits( ([
  "northeast" : DIR+"/rooms/9_5_-2.c",
  "southeast" : DIR+"/rooms/9_7_-2.c"
  ]) );

}

