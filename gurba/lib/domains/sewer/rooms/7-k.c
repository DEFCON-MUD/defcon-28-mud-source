inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 7-k" );
set_objects( DIR+"/monsters/sub-average_parrot_5.c");
 set_exits( ([
  "north" : DIR+"/rooms/6-k.c",
  "west" : DIR+"/rooms/7-j.c"
  ]) );
  set_long( "This is a narrow tunnel, illuminated only by the iridium glow of the sediment in this hellhole. The walls and floors are covered with mud. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe horror continues to the north, and west.%^RESET%^");
}
