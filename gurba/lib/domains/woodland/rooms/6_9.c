inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("woodland");
  set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");
  set_coords(({ 6, 9 }));
  set_dimensions(({ 12, 16 }));

  set_short( "Woodland" );
  set_long( "This is sprawling woodland, trees can be seen everywhere while critters can be heard in the distance. " );

 set_exits( ([
  "west" : DIR+"/rooms/5_9.c",
  "southeast" : DIR+"/rooms/7_10.c",
  "north" : DIR+"/rooms/6_8.c",
  "northeast" : DIR+"/rooms/7_8.c"
  ]) );

}

