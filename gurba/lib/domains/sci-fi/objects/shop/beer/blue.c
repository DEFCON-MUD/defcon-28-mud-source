#include "../../../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("blue potion");
   add_id("blue");
   add_id("potion");
   set_short("A blue potion");
   set_long("A small fancy bottle, with a faintly glowing blue liquid in it.  " +
      "It grants 150 hp\n");
   set_eatable(1);
   set_gettable(1);
   set_value(1500);
   set_weight(2);
}

int do_eat(void) {
   int x;

   x = 150;
   write("You drink the potion.  You feel a warmth in your chest.\n");
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + " drinks an blue potion.\n");
   this_player()->increase_hp(x);
   this_object()->destruct();
}
