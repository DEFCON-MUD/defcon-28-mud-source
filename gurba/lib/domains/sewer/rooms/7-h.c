inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 7-h" );
set_objects( DIR+"/monsters/mediocre_parrot_4.c");
 set_exits( ([
  "east" : DIR+"/rooms/7-i.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the iridium glow of the sediment in this hellhole. The walls and floors are covered with dust. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe sewer continues to the east.%^RESET%^");
}
