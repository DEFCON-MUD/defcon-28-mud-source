inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 7, 7, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Labyrinth" );
  set_long( "This is a cramped hallway, illuminated only by the blue glow of the crud in this pit. The walls and floors are covered with oil. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^" );

  set_objects(
    DIR+"/npc/salesdroid.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/6_7_-2.c",
  "northwest" : DIR+"/rooms/6_6_-2.c",
  "north" : DIR+"/rooms/7_6_-2.c"
  ]) );

}

