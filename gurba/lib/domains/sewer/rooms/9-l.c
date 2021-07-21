inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 9-l" );
set_objects( DIR+"/monsters/mediocre_snake_4.c");
 set_exits( ([
  "north" : DIR+"/rooms/8-l.c",
  "south" : DIR+"/rooms/10-l.c",
  "east" : DIR+"/rooms/9-m.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the orange glow of the gunk in this stink-pit. The walls and floors are covered with oil. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nYou may be able to find escape to the north, south, and east.%^RESET%^");
}
