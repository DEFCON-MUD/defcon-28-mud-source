#include "../domain.h"

inherit "/std/weapon";

void set_sword_skill(string s) {
   if (!is_standard_weapon_skill(s)) {
      s = "small";
   }
   set_weapon_skill("combat/edge/" + s);
}

void setup(void) {
   set_id("blade");
   set_adj("small");
   set_short("A small blade");
   set_long("This is a standard issued blade, saddly corporate can't afford bullets, lightsabers or anything else so this is what they will sell you.");
   set_gettable(1);

   set_min_damage(5);
   set_max_damage(10);
   set_hit_bonus(2);

   set_wield_type("single");
   set_weapon_actions(({
      "slash", "slice", "dice", "cut", "gash", "stab", "poke", "gouge"
      }));
   set_sword_skill("small");

   set_value(1000);
   set_size(2);
   set_weight(600);
}
