inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 11-i" );
set_objects( DIR+"/monsters/newbie_snake_2.c");
 set_exits( ([
  "north" : DIR+"/rooms/10-i.c",
  "south" : DIR+"/rooms/12-i.c",
  "west" : DIR+"/rooms/11-h.c",
  "northeast" : DIR+"/rooms/10-j.c"
  ]) );
  set_long( "This is a wide corridor, illuminated only by the red glow of the muck in this stink-pit. The walls and floors are covered with blood. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe horror continues to the north, south, west, and northeast.%^RESET%^");
}
