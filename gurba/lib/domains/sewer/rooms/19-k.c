inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 19-k" );
set_objects( DIR+"/monsters/newbie_ferret_2.c");
 set_exits( ([
  "east" : DIR+"/rooms/19-l.c",
  "west" : DIR+"/rooms/19-j.c"
  ]) );
  set_long( "This is a narrow corridor, illuminated only by the iridium glow of the sediment in this hellhole. The walls and floors are covered with blood. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe horror continues to the east, and west.%^RESET%^");
}
