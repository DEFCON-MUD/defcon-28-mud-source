inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  #include "area.h"
  add_area("woodland");
  set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");
  set_coords(({ 10, 3 }));
  set_dimensions(({ 12, 16 }));

  set_short( "Woodland" );
  set_long( "This is sprawling woodland, trees can be seen everywhere while critters can be heard in the distance. " );

 set_exits( ([
  "west" : DIR+"/rooms/9_3.c",
  "northwest" : DIR+"/rooms/9_2.c",
  "north" : DIR+"/rooms/10_2.c",
  "northeast" : DIR+"/rooms/11_2.c",
  "east" : DIR+"/rooms/11_3.c",
  "southeast" : DIR+"/rooms/11_4.c",
  "south" : DIR+"/rooms/10_4.c",
  "southwest" : DIR+"/rooms/9_4.c"
  ]) );

}

