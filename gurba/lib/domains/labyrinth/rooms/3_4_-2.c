inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 3, 4, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Labyrinth" );
  set_long( "This is a narrow corridor, illuminated only by the green glow of the gunk in this hellhole. The walls and floors are covered with oil. It smells like a hacker convention in here.%^RESET%^" );

  set_objects(
    DIR+"/npc/salesdroid.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/2_4_-2.c",
  "north" : DIR+"/rooms/3_3_-2.c",
  "northeast" : DIR+"/rooms/4_3_-2.c",
  "east" : DIR+"/rooms/4_4_-2.c",
  "southeast" : DIR+"/rooms/4_5_-2.c",
  "southwest" : DIR+"/rooms/2_5_-2.c",
  "up" : DIR+"/rooms/3_4_-1.c"
  ]) );

}

