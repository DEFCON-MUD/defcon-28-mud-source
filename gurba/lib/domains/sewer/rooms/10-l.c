inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 10-l" );
set_objects( DIR+"/monsters/average_rat_6.c");
 set_exits( ([
  "north" : DIR+"/rooms/9-l.c",
  "south" : DIR+"/rooms/11-l.c",
  "west" : DIR+"/rooms/10-k.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the green glow of the gunk in this stink-pit. The walls and floors are covered with oil. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe horror continues to the north, south, and west.%^RESET%^");
}
