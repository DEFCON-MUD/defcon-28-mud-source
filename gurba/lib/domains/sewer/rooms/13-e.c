inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 13-e" );
set_objects( DIR+"/monsters/meh_rat_3.c");
 set_exits( ([
  "south" : DIR+"/rooms/14-e.c",
  "east" : DIR+"/rooms/13-f.c"
  ]) );
  set_long( "This is a wide corridor, illuminated only by the greenish glow of the sediment in this stink-pit. The walls and floors are covered with dust. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nYou may be able to find escape to the south, and east.%^RESET%^");
}
