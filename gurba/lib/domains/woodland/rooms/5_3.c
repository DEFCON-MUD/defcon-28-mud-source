inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("woodland");
  set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");
  set_coords(({ 5, 3 }));
  set_dimensions(({ 12, 16 }));

  set_short( "Woodland" );
  set_long( "This is sprawling woodland, trees can be seen everywhere while critters can be heard in the distance. " );

 set_exits( ([
  "north" : DIR+"/rooms/5_2.c",
  "south" : DIR+"/rooms/5_4.c",
  "east" : DIR+"/rooms/6_3.c",
  "southeast" : DIR+"/rooms/6_4.c"
  ]) );

}

