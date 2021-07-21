inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("labyrinth");
  set_domainname("labyrinth");
  set_coords(({ 6, 4, -2 }));
  set_dimensions(({ 10, 10 }));

  set_short( "Labyrinth" );
  set_long( "This is a broad tunnel, illuminated only by the red glow of the muck in this hellhole. The walls and floors are covered with liquid. The air smells like it hasn't been cycled in a while, you are getting dizzy.%^RESET%^" );

  set_objects(
    DIR+"/npc/coder.c"
  );
 set_exits( ([
  "north" : DIR+"/rooms/6_3_-2.c",
  "east" : DIR+"/rooms/7_4_-2.c",
  "south" : DIR+"/rooms/6_5_-2.c"
  ]) );

}

