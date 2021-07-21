#include "../../../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("purple potion");
   add_id("purple");
   add_id("potion");
   set_short("A purple potion");
   set_long("A small fancy bottle, with a faintly glowing purple liquid in it.  " +
      "It grants 200 hp\n");
   set_eatable(1);
   set_gettable(1);
   set_value(2000);
   set_weight(2);
}

int do_eat(void) {
   int x;

   x = 200;
   write("You drink the potion.  You feel a warmth in your chest.\n");
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + " drinks an purple potion.\n");
   this_player()->increase_hp(x);
   this_object()->destruct();
}
