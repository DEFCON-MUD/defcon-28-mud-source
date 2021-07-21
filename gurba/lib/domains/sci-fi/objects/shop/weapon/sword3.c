inherit "/std/weapon";

#include "../../../domain.h"

void setup(void) {
  set_id("gold sword");
  add_id("sword");
  add_id("gold");
  add_id("gold sword");
  set_value(1800);
  set_size(3);
  set_weight(30);
  set_weapon_action("slash");
  set_weapon_skill("combat/sharp/small");
  set_short("A gold sword");
  set_long("A gold sword");
  set_min_damage(3);
  set_max_damage(30);
  set_hit_bonus(6);
}
