inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("woodland");
  set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");
  set_coords(({ 10, 1 }));
  set_dimensions(({ 12, 16 }));

  set_short( "Woodland" );
  set_long( "This is sprawling woodland, trees can be seen everywhere while critters can be heard in the distance. " );

 set_exits( ([
  "west" : DIR+"/rooms/9_1.c",
  "southwest" : DIR+"/rooms/9_2.c",
  "south" : DIR+"/rooms/10_2.c",
  "southeast" : DIR+"/rooms/11_2.c",
  "east" : DIR+"/rooms/11_1.c"
  ]) );

}

