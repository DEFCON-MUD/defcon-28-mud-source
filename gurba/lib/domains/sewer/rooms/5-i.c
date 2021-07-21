inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 5-i" );
set_objects( DIR+"/monsters/uninitiated_rat_1.c");
 set_exits( ([
  "north" : DIR+"/rooms/4-i.c",
  "south" : DIR+"/rooms/6-i.c"
  ]) );
  set_long( "This is a wide hallway, illuminated only by the red glow of the gunk in this area. The walls and floors are covered with liquid. It smells like a hacker convention in here.%^RESET%^\n\nThe sewer continues to the north, and south.%^RESET%^");
}
