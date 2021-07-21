inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 11-m" );
set_objects( DIR+"/monsters/average_eel_6.c");
 set_exits( ([
  "east" : DIR+"/rooms/11-n.c",
  "west" : DIR+"/rooms/11-l.c"
  ]) );
  set_long( "This is a narrow hallway, illuminated only by the orange glow of the muck in this hellhole. The walls and floors are covered with oil. The smell is outright dreadful.%^RESET%^\n\nThe horror continues to the east, and west.%^RESET%^");
}
