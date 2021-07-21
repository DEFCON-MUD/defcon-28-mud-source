inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 7-l" );
set_objects( DIR+"/monsters/average_snake_6.c");
 set_exits( ([
  "south" : DIR+"/rooms/8-l.c",
  "northwest" : DIR+"/rooms/6-k.c",
  "southeast" : DIR+"/rooms/8-m.c",
  "southwest" : DIR+"/rooms/8-k.c"
  ]) );
  set_long( "This is a narrow corridor, illuminated only by the red glow of the gunk in this hellhole. The walls and floors are covered with liquid. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe sewer continues to the south, northwest, southeast, and southwest.%^RESET%^");
}
