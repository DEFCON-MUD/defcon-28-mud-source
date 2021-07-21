inherit "/std/room";
inherit "/std/evil/shop";

#include "../domain.h"
 
void setup(void) {

   add_area("woodland");

   set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");
   set_coords(({ 1, 0 }));
   set_dimensions(({ 2, 1 }));
   set_mapstart(({ 0, 0} ));

   add_action("do_order", "order");
   add_action("do_order", "list");

   set_short("A sketchy shop");
   set_long("You are in a sketchy shop. You can %^MAGENTA%^order%^RESET%^ stuff here.");
   set_long_mxp("You are in a sketchy shop. You can %^MXP_LSM%^<send \"order\">%^MAGENTA%^order</send>%^RESET%^ stuff here.");
   set_exits(([
     "west" : "/domains/woodland/rooms/5_16"
   ]));
}

