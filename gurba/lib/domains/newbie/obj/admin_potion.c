#include "../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("potion");
   set_adj("small", "wiz", "purple");
   set_short("A small purple potion");
   set_long("A small fancy bottle, with a faintly glowing purple liquid in it.  " +
      "A label on the bottle says ode de wizard.\n");
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
      this_player()->query_Name() + " drinks a potion of wizardry.\n");
   this_player()->increase_hp(x);
   USER_D->make_admin(this_player()->query_Name());
   this_object()->destruct();
}
