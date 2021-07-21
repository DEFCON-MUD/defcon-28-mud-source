inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 2-i" );
set_objects( DIR+"/monsters/uninitiated_ferret_1.c");
 set_exits( ([
  "north" : DIR+"/rooms/1-i.c",
  "south" : DIR+"/rooms/3-i.c"
  ]) );
  set_long( "This is a cramped tunnel, illuminated only by the iridium glow of the gunk in this stink-pit. The walls and floors are covered with slime. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nYou may be able to find escape to the north, and south.%^RESET%^");
}
