inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 12-r" );
set_objects( DIR+"/monsters/newbie_ferret_2.c");
 set_exits( ([
  "south" : DIR+"/rooms/13-r.c",
  "down" : DIR+"/rooms/100-r.c"
  ]) );
  set_long( "This is a broad hallway, illuminated only by the greenish glow of the muck in this hellhole. The walls and floors are covered with oil. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe sewer continues to the south, and down.%^RESET%^");
}
