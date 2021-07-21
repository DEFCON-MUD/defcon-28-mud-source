inherit "/std/room";
#include "../domain.h"

void setup(void) {

   add_area("woodland_start");

   set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");
   set_coords(({ 0, 0 }));
   set_dimensions(({ 2, 1 }));
   set_mapstart(({ 0, 0} ));

   set_short("A large open field");
   set_long("You are at the start of a great forest, the area feels strange and " + 
    "evil. Venture forth to destroy the vile creatures within, you may look at the " +
    "sign to find out more. A fountain is here.");
   set_long_mxp("You are at the start of a great forest, the area feels strange and " + 
    "evil. Venture forth to destroy the vile creatures within, you may look at the " +
    "%^MXP_LSM%^<send \"read sign\">sign</send> to find out more. A fountain is here.");
   add_item("fountain", "This looks like a fountain of youth, type %^MAGENTA%^XJPjsdTiSP6HK3eRu37%^RESET%^ to restore your endurance");
   add_action("XJPjsdTiSP6HK3eRu37", "XJPjsdTiSP6HK3eRu37");
   set_exits(([
     "north" : "/domains/woodland/rooms/5_15",
     "south" : "/domains/newbie/rooms/tree",
     "west" : "/domains/woodland/rooms/mine",
     "east" : "/domains/woodland/rooms/shop"
   ]));
   set_objects(
    DIR+"/obj/sign.c"
  );

}

int XJPjsdTiSP6HK3eRu37 (string args) {
  this_player()->set_end(this_player()->query_max_end());
  write("A sparkling light envelops you and you feel like you can take on the world...\n");
  return 1;
}
