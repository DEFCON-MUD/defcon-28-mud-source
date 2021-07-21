inherit "/std/monster";

void setup(void) {
   set_name("party parrot cultist");
   add_adj("cultist");
   set_short("A fanatical, mad cultist of the party parrot");
   set_long("The cultist is foaming at the mouth, gibbering about animated emoji and weird new memes.");
   set_race("human");
   set_level(5);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 20);
   set_skill("combat/defense", 10);
   set_aggressive(1);
}
