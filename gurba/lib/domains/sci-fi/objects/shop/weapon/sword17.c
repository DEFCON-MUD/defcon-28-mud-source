inherit "/std/weapon";

#include "../../../domain.h"

void setup(void) {
  set_id("mogium sword");
  add_id("sword");
  add_id("mogium");
  add_id("mogium sword");
  set_value(57800);
  set_size(17);
  set_weight(170);
  set_weapon_action("slash");
  set_weapon_skill("combat/sharp/small");
  set_short("A mogium sword");
  set_long("A mogium sword");
  set_min_damage(17);
  set_max_damage(170);
  set_hit_bonus(34);
}
