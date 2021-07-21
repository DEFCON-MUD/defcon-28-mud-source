inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 10-i" );
set_objects( DIR+"/monsters/strong_eel_7.c");
 set_exits( ([
  "south" : DIR+"/rooms/11-i.c",
  "west" : DIR+"/rooms/10-h.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the redish glow of the gunk in this area. The walls and floors are covered with slime. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe sewer continues to the south, and west.%^RESET%^");
}
