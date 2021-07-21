inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 12-b" );
set_objects( DIR+"/monsters/sub-average_lizard_5.c");
 set_exits( ([
  "south" : DIR+"/rooms/13-b.c",
  "east" : DIR+"/rooms/12-c.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the purple glow of the sediment in this area. The walls and floors are covered with dust. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe sewer continues to the south, and east.%^RESET%^");
}
