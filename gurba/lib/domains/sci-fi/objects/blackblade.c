#include "../domain.h"

inherit "/std/weapon";

void set_sword_skill(string s) {
   if (!is_standard_weapon_skill(s)) {
      s = "medium";
   }
   set_weapon_skill("combat/edge/" + s);
}

void setup(void) {
   set_id("black blade");
   set_adj("black");
   set_short("A sleek, black blade");
   set_long("This 3.5' long blade is the color of midnight. It has an ornate, golden crossguard and has a ruby that emits a bloody pulse of light. It is as if this sword craves for the blood of its wielder's foes.");
   set_gettable(1);

   set_min_damage(5);
   set_max_damage(25);
   set_hit_bonus(5);

   set_wield_type("single");
   set_wield_message("$N $vgrab $p $o. Ready!");
   set_unwield_message("$N $vloosen $p $vgrip on $o, and $vput it away.");
   set_weapon_actions(({
      "slash", "slice", "dice", "cut", "gash", "stab", "poke", "gouge"
      }));
   set_sword_skill("medium");

   set_value(30);
   set_size(2);
   set_weight(2);
}
