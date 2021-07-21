inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 13-j" );
set_objects( DIR+"/monsters/average_snake_6.c");
 set_exits( ([
  "north" : DIR+"/rooms/12-j.c",
  "south" : DIR+"/rooms/14-j.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the iridium glow of the sediment in this stink-pit. The walls and floors are covered with oil. It smells like a hacker convention in here.%^RESET%^\n\nThe horror continues to the north, and south.%^RESET%^");
}
