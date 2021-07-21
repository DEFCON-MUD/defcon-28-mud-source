inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 14-c" );
set_objects( DIR+"/monsters/mediocre_eel_4.c");
 set_exits( ([
  "east" : DIR+"/rooms/14-d.c",
  "southeast" : DIR+"/rooms/15-d.c"
  ]) );
  set_long( "This is a wide hallway, illuminated only by the purple glow of the sediment in this stink-pit. The walls and floors are covered with slime. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe sewer continues to the east, and southeast.%^RESET%^");
}
