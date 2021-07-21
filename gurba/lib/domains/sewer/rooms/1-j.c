inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 1-j" );
set_objects( DIR+"/monsters/average_lizard_6.c");
 set_exits( ([
  "south" : DIR+"/rooms/2-j.c",
  "east" : DIR+"/rooms/1-k.c",
  "southeast" : DIR+"/rooms/2-k.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the green glow of the gunk in this hellhole. The walls and floors are covered with slime. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe sewer continues to the south, east, and southeast.%^RESET%^");
}
