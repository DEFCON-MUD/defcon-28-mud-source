inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("woodland");
  set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");
  set_coords(({ 8, 2 }));
  set_dimensions(({ 12, 16 }));

  set_short( "Woodland" );
  set_long( "This is sprawling woodland, trees can be seen everywhere while critters can be heard in the distance. " );

 set_exits( ([
  "west" : DIR+"/rooms/7_2.c",
  "north" : DIR+"/rooms/8_1.c",
  "northeast" : DIR+"/rooms/9_1.c",
  "east" : DIR+"/rooms/9_2.c",
  "southeast" : DIR+"/rooms/9_3.c",
  "south" : DIR+"/rooms/8_3.c"
  ]) );

}

