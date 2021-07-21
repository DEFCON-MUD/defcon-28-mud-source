inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Access Tunnel - 5-q" );
set_objects( DIR+"/monsters/uninitiated_snake_1.c");
 set_exits( ([
  "north" : DIR+"/rooms/4-q.c",
  "south" : DIR+"/rooms/6-q.c"
  ]) );
  set_long( "This is a narrow corridor, illuminated only by the orange glow of the muck in this area. The walls and floors are covered with slime. Musty air that doesn't seem to have been ventilated for a while brushes up against you as you move around here.%^RESET%^\n\nThe sewer continues to the north, and south.%^RESET%^");
}
