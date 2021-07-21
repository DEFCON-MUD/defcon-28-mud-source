#include "../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("energy drink");
   add_id("energy");
   add_id("drink");
   add_id("energy drink");
   set_short("Energy Drink");
   set_long("A small fancy bottle, with a faintly glowing red liquid in it.  " +
      "A label on the bottle says evil mogs special drink.\n");
   set_eatable(1);
   set_gettable(1);
   set_value(100);
   set_weight(100);
}

int do_eat(void) {
   int x;

   x = random(5) + 1;
   write("You drink the energy drink.  You feel a warmth in your chest.\n");
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + " drinks an energy drink.\n");
   this_player()->increase_hp(x);
   this_player()->increase_expr(100);
   this_object()->destruct();
}
