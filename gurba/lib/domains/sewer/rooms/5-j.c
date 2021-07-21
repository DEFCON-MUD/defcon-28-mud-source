inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 5-j" );
set_objects( DIR+"/monsters/sub-average_parrot_5.c");
 set_exits( ([
  "south" : DIR+"/rooms/6-j.c",
  "northwest" : DIR+"/rooms/4-i.c",
  "southeast" : DIR+"/rooms/6-k.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the greenish glow of the gunk in this stink-pit. The walls and floors are covered with blood. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe horror continues to the south, northwest, and southeast.%^RESET%^");
}
