inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 11-e" );
set_objects( DIR+"/monsters/newbie_worm_2.c");
 set_exits( ([
  "east" : DIR+"/rooms/11-f.c",
  "west" : DIR+"/rooms/11-d.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the red glow of the muck in this stink-pit. The walls and floors are covered with oil. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nYou may be able to find escape to the east, and west.%^RESET%^");
}
