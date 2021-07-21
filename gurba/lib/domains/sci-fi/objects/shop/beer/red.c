#include "../../../domain.h"

inherit "/std/object";

void setup(void) {
   set_id("red potion");
   add_id("red");
   add_id("potion");
   set_short("A red potion");
   set_long("A small fancy bottle, with a faintly glowing red liquid in it.  " +
      "It grants 100 hp\n");
   set_eatable(1);
   set_gettable(1);
   set_value(1000);
   set_weight(2);
}

int do_eat(void) {
   int x;

   x = 100;
   write("You drink the potion.  You feel a warmth in your chest.\n");
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + " drinks a red potion.\n");
   this_player()->increase_hp(x);
   this_object()->destruct();
}
