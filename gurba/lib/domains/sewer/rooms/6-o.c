inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 6-o" );
set_objects( DIR+"/monsters/mediocre_parrot_4.c");
 set_exits( ([
  "south" : DIR+"/rooms/7-o.c",
  "northeast" : DIR+"/rooms/5-p.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the greenish glow of the muck in this stink-pit. The walls and floors are covered with slime. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe horror continues to the south, and northeast.%^RESET%^");
}
