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
   string WIZARDPOTION;
   WIZARDPOTION = FLAG_D->query_flag("WIZARDPOTION");
   x = random(5) + 1;
   write("You drink the potion.  You feel a warmth in your chest.\n");
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + " drinks a potion of wizardry.\n");
   this_player()->increase_hp(x);
   if (this_player()->is_completed_quest("Wizard") == 1) {
     write("You have already completed the wizard quest.\n");
     write("Your flag is " + WIZARDPOTION +"\n");
     this_player()->move(this_player()->query_start_room());
     call_other(this_player(), "do_look", this_environment());
   } else {
     write("\nCongrats you beat the wizard quest\n");
     CHANNEL_D->chan_send_string("announce", "", this_player()->query_name() +" has completed the wizard quest", 1);
     write("Your flag is " + WIZARDPOTION +"\n");
     write("\n");
     this_player()->add_completed_quest("Wizard");
     this_player()->increase_expr(20000);
     this_player()->move(this_player()->query_start_room());
     call_other(this_player(), "do_look", this_environment());
   }
   this_object()->destruct();
}
