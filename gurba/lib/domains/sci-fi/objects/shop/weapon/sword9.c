inherit "/std/weapon";

#include "../../../domain.h"

void setup(void) {
  set_id("tungsten-carbide sword");
  add_id("sword");
  add_id("tungsten-carbide");
  add_id("tungsten-carbide sword");
  set_value(16200);
  set_size(9);
  set_weight(90);
  set_weapon_action("slash");
  set_weapon_skill("combat/sharp/small");
  set_short("A tungsten-carbide sword");
  set_long("A tungsten-carbide sword");
  set_min_damage(9);
  set_max_damage(90);
  set_hit_bonus(18);
}
