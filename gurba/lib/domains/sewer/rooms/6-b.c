inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 6-b" );
set_objects( DIR+"/monsters/newbie_ferret_2.c");
 set_exits( ([
  "north" : DIR+"/rooms/5-b.c",
  "east" : DIR+"/rooms/6-c.c",
  "southwest" : DIR+"/rooms/7-a.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the redish glow of the gunk in this hellhole. The walls and floors are covered with dust. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe sewer continues to the north, east, and southwest.%^RESET%^");
}
