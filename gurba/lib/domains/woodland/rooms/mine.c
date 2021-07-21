inherit "/std/room";
inherit "/std/evil/mine";

#include "../domain.h"
void setup( void ) {

  #include "area.h"
  set_coords(({ 1, 1 }));
  set_dimensions(({ 1, 1 }));
  add_area( "woodland" );
  set_short( "Woodland Crypto Currency Mines" );
  set_long( "So years ago the company sold off all its mines, it replaced them with digital currency mines. All the corezite that was here was mined out years ago to make the fusion reactors that make up this digital mine. Chairs are all over the place lined up against terminals.\n\nYou should try to '%^EXT_129%^crypto%^RESET%^' here." );

  add_action("do_crypto", "crypto");

 set_exits( ([
  "east" : "/domains/woodland/rooms/5_16"
  ]) );
}
