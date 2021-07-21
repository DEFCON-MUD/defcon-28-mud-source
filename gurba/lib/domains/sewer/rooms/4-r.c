inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 4-r" );
set_objects( DIR+"/monsters/sub-average_rat_5.c");
 set_exits( ([
  "south" : DIR+"/rooms/5-r.c",
  "west" : DIR+"/rooms/4-q.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the orange glow of the gunk in this hellhole. The walls and floors are covered with liquid. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe sewer continues to the south, and west.%^RESET%^");
}
