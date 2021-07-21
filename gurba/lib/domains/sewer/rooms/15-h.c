inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 15-h" );
set_objects( DIR+"/monsters/meh_ferret_3.c");
 set_exits( ([
  "north" : DIR+"/rooms/14-h.c",
  "south" : DIR+"/rooms/16-h.c"
  ]) );
  set_long( "This is a narrow hallway, illuminated only by the iridium glow of the sediment in this stink-pit. The walls and floors are covered with liquid. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe sewer continues to the north, and south.%^RESET%^");
}
