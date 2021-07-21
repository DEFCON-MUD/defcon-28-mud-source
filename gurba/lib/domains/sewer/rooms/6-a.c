inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 6-a" );
set_objects( DIR+"/monsters/mediocre_eel_4.c");
 set_exits( ([
  "south" : DIR+"/rooms/7-a.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the greenish glow of the muck in this area. The walls and floors are covered with slime. The smell is outright dreadful.%^RESET%^\n\nYou may be able to find escape to the south.%^RESET%^");
}
