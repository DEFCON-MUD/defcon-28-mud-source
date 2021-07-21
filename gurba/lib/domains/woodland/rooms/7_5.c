inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("woodland");
  set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");
  set_coords(({ 7, 5 }));
  set_dimensions(({ 12, 16 }));

  set_short( "Woodland" );
  set_long( "This is sprawling woodland, trees can be seen everywhere while critters can be heard in the distance. " );

 set_exits( ([
  "northwest" : DIR+"/rooms/6_4.c",
  "southwest" : DIR+"/rooms/6_6.c",
  "southeast" : DIR+"/rooms/8_6.c",
  "northeast" : DIR+"/rooms/8_4.c"
  ]) );

}

