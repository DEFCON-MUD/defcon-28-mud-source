inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("woodland");
  set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");
  set_coords(({ 9, 6 }));
  set_dimensions(({ 12, 16 }));

  set_short( "Woodland" );
  set_long( "This is sprawling woodland, trees can be seen everywhere while critters can be heard in the distance. " );

 set_exits( ([
  "northwest" : DIR+"/rooms/8_5.c",
  "northeast" : DIR+"/rooms/10_5.c",
  "east" : DIR+"/rooms/10_6.c",
  "southeast" : DIR+"/rooms/10_7.c"
  ]) );

}

