inherit "/std/monster";

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
