inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 6-h" );
set_objects( DIR+"/monsters/mediocre_alligator_4.c");
 set_exits( ([
  "north" : DIR+"/rooms/5-h.c",
  "east" : DIR+"/rooms/6-i.c",
  "west" : DIR+"/rooms/6-g.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the redish glow of the gunk in this stink-pit. The walls and floors are covered with oil. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe horror continues to the north, east, and west.%^RESET%^");
}
