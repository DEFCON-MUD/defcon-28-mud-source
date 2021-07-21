inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 8-p" );
set_objects( DIR+"/monsters/sub-average_mouse_5.c");
 set_exits( ([
  "south" : DIR+"/rooms/9-p.c",
  "west" : DIR+"/rooms/8-o.c"
  ]) );
  set_long( "This is a cramped hallway, illuminated only by the orange glow of the sediment in this hellhole. The walls and floors are covered with oil. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe sewer continues to the south, and west.%^RESET%^");
}
