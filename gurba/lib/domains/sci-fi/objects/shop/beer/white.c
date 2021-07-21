#include "../../../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("white potion");
   add_id("white");
   add_id("potion");
   set_short("A yellow potion");
   set_long("A small fancy bottle, with a faintly glowing white liquid in it.  " +
      "It grants 10 hp\n");
   set_eatable(1);
   set_gettable(1);
   set_value(100);
   set_weight(2);
}

int do_eat(void) {
   int x;

   x = 10;
   write("You drink the potion.  You feel a warmth in your chest.\n");
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + " drinks a white potion.\n");
   this_player()->increase_hp(x);
   this_object()->destruct();
}
