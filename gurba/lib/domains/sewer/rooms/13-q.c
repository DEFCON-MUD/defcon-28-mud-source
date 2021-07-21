inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 13-q" );
set_objects( DIR+"/monsters/mediocre_lizard_4.c");
 set_exits( ([
  "east" : DIR+"/rooms/13-r.c",
  "west" : DIR+"/rooms/13-p.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the redish glow of the muck in this hellhole. The walls and floors are covered with blood. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe horror continues to the east, and west.%^RESET%^");
}
