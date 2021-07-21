inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 6, 1, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Hallway" );
  set_long( "This is a wide tunnel, illuminated only by the green glow of the glorzo in this pit. The walls and floors are covered with slime. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^" );

  set_objects(
    DIR+"/npc/agent.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/5_1_-2.c",
  "south" : DIR+"/rooms/6_2_-2.c",
  "southeast" : DIR+"/rooms/7_2_-2.c",
  "east" : DIR+"/rooms/7_1_-2.c"
  ]) );

}

