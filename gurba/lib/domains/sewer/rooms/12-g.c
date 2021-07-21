inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 12-g" );
set_objects( DIR+"/monsters/mediocre_alligator_4.c");
 set_exits( ([
  "south" : DIR+"/rooms/13-g.c",
  "east" : DIR+"/rooms/12-h.c",
  "west" : DIR+"/rooms/12-f.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the purple glow of the gunk in this hellhole. The walls and floors are covered with oil. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe horror continues to the south, east, and west.%^RESET%^");
}
