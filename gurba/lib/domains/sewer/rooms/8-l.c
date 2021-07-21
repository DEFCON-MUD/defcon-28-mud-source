inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 8-l" );
set_objects( DIR+"/monsters/newbie_ferret_2.c");
 set_exits( ([
  "north" : DIR+"/rooms/7-l.c",
  "south" : DIR+"/rooms/9-l.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the orange glow of the gunk in this hellhole. The walls and floors are covered with dust. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe horror continues to the north, and south.%^RESET%^");
}
