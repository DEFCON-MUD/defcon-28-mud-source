inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 13-a" );
set_objects( DIR+"/monsters/strong_ferret_7.c");
 set_exits( ([
  "north" : DIR+"/rooms/12-a.c",
  "south" : DIR+"/rooms/14-a.c"
  ]) );
  set_long( "This is a cramped corridor, illuminated only by the purple glow of the gunk in this stink-pit. The walls and floors are covered with liquid. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe horror continues to the north, and south.%^RESET%^");
}
