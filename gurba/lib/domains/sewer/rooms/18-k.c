inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 18-k" );
set_objects( DIR+"/monsters/newbie_lizard_2.c");
 set_exits( ([
  "north" : DIR+"/rooms/17-k.c",
  "east" : DIR+"/rooms/18-l.c"
  ]) );
  set_long( "This is a wide tunnel, illuminated only by the orange glow of the sediment in this area. The walls and floors are covered with dust. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe horror continues to the north, and east.%^RESET%^");
}
