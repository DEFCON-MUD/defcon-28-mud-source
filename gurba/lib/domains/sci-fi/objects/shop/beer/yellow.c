#include "../../../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("yellow potion");
   add_id("yellow");
   add_id("potion");
   set_short("A yellow potion");
   set_long("A small fancy bottle, with a faintly glowing liquid in it.  " +
      "It grants 20 hp\n");
   set_eatable(1);
   set_gettable(1);
   set_value(200);
   set_weight(2);
}

int do_eat(void) {
   int x;

   x = 20;
   write("You drink the potion.  You feel a warmth in your chest.\n");
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + " drinks a yellow potion.\n");
   this_player()->increase_hp(x);
   this_object()->destruct();
}
