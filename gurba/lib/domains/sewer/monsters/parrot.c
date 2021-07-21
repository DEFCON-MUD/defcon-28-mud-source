inherit "/std/monster";

#include "../domain.h"

void setup(void) {
   set_name("parrot");
   add_adj("party");
   set_short("THE party parrot");
   set_long("The multi-colored parrot looks ready to party, but it has also mistaken your cranium as a mate.");
   set_race("bird");
   set_level(20);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 100);
   set_skill("combat/defense", 100);
   set_aggressive(1);
}


void monster_died(void) {
  string PARROT;
  PARROT = FLAG_D->query_flag("PARROT");
 if (killer->is_completed_quest("Parrot") == 1) {
   write("You have already completed the parrot quest.\n");
   write("Your flag is " + PARROT + " \n");
 } else {
   CHANNEL_D->chan_send_string("announce", "", killer->query_name() +" has completed the parrot quest", 1);
   killer->add_completed_quest("Parrot");
   killer->increase_expr(20000);
   killer->set_title("$N the Parrot Killer");
   write("Your flag is " + PARROT + " \n");
 }
}
