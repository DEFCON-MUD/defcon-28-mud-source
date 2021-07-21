inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 8, 1, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Labyrinth" );
  set_long( "This is a wide hallway, illuminated only by the blue glow of the gunk in this hellhole. The walls and floors are covered with liquid. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^" );

  set_objects(
    DIR+"/npc/monkey.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/7_1_-2.c",
  "south" : DIR+"/rooms/8_2_-2.c",
  "east" : DIR+"/rooms/9_1_-2.c",
  "southeast" : DIR+"/rooms/9_2_-2.c"
  ]) );

}

