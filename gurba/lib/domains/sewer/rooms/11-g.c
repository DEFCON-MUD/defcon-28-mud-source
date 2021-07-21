inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 11-g" );
set_objects( DIR+"/monsters/strong_lizard_7.c");
 set_exits( ([
  "east" : DIR+"/rooms/11-h.c",
  "west" : DIR+"/rooms/11-f.c"
  ]) );
  set_long( "This is a narrow hallway, illuminated only by the orange glow of the sediment in this stink-pit. The walls and floors are covered with liquid. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe sewer continues to the east, and west.%^RESET%^");
}
