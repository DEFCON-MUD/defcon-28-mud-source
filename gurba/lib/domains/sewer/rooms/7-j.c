inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 7-j" );
set_objects( DIR+"/monsters/average_ferret_6.c");
 set_exits( ([
  "north" : DIR+"/rooms/6-j.c",
  "east" : DIR+"/rooms/7-k.c"
  ]) );
  set_long( "This is a cramped tunnel, illuminated only by the iridium glow of the muck in this hellhole. The walls and floors are covered with slime. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe horror continues to the north, and east.%^RESET%^");
}
