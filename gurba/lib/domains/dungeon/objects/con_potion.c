#include "../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("potion");
   set_adj("small", "con", "green");
   set_short("A small green potion");
   set_long("A small fancy bottle, with a faintly glowing green liquid in it.  " +
      "A label on the bottle says ode de con\n");
   set_eatable(1);
   set_gettable(1);
   set_value(10);
   set_weight(2);
}

int do_eat(void) {
   int x;

   x = random(5) + 1;
   write("You drink the potion.  You feel a warmth in your chest.\n");
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + " drinks a potion of con.\n");
   this_player()->increase_hp(x);
   this_player()->increase_expr(1000);
   this_player()->add_base_stat("con", 1);
    this_object()->destruct();
}
