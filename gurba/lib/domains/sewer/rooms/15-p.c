inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 15-p" );
set_objects( DIR+"/monsters/newbie_snake_2.c");
 set_exits( ([
  "south" : DIR+"/rooms/16-p.c",
  "northeast" : DIR+"/rooms/14-q.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the orange glow of the sediment in this stink-pit. The walls and floors are covered with dust. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe sewer continues to the south, and northeast.%^RESET%^");
}
