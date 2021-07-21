inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("woodland");
  set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");
  set_coords(({ 1, 10 }));
  set_dimensions(({ 12, 16 }));

  set_short( "Woodland" );
  set_long( "This is sprawling woodland, trees can be seen everywhere while critters can be heard in the distance. " );

 set_exits( ([
  "southwest" : DIR+"/rooms/0_11.c",
  "west" : DIR+"/rooms/0_10.c",
  "northwest" : DIR+"/rooms/0_9.c",
  "east" : DIR+"/rooms/2_10.c"
  ]) );

}

