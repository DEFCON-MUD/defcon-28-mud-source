inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 11-c" );
set_objects( DIR+"/monsters/newbie_snake_2.c");
 set_exits( ([
  "east" : DIR+"/rooms/11-d.c",
  "west" : DIR+"/rooms/11-b.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the greenish glow of the sediment in this stink-pit. The walls and floors are covered with oil. It smells like a hacker convention in here.%^RESET%^\n\nThe sewer continues to the east, and west.%^RESET%^");
}
