inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 5-e" );
set_objects( DIR+"/monsters/newbie_ferret_2.c");
 set_exits( ([
  "northwest" : DIR+"/rooms/4-d.c",
  "southeast" : DIR+"/rooms/6-f.c"
  ]) );
  set_long( "This is a cramped tunnel, illuminated only by the redish glow of the sediment in this hellhole. The walls and floors are covered with dust. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe horror continues to the northwest, and southeast.%^RESET%^");
}
