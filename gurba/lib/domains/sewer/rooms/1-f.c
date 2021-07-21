inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 1-f" );
set_objects( DIR+"/monsters/sub-average_parrot_5.c");
 set_exits( ([
  "east" : DIR+"/rooms/1-g.c",
  "southwest" : DIR+"/rooms/2-e.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the green glow of the gunk in this hellhole. The walls and floors are covered with liquid. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe sewer continues to the east, and southwest.%^RESET%^");
}
