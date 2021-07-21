inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("woodland");
  set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");
  set_coords(({ 9, 2 }));
  set_dimensions(({ 12, 16 }));

  set_short( "Woodland" );
  set_long( "This is sprawling woodland, trees can be seen everywhere while critters can be heard in the distance. " );

 set_exits( ([
  "west" : DIR+"/rooms/8_2.c",
  "northwest" : DIR+"/rooms/8_1.c",
  "north" : DIR+"/rooms/9_1.c",
  "northeast" : DIR+"/rooms/10_1.c",
  "east" : DIR+"/rooms/10_2.c",
  "southeast" : DIR+"/rooms/10_3.c",
  "south" : DIR+"/rooms/9_3.c",
  "southwest" : DIR+"/rooms/8_3.c"
  ]) );

}

