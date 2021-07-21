inherit "/std/weapon";

#include "../../../domain.h"

void setup(void) {
  set_id("tungsten-mogium sword");
  add_id("sword");
  add_id("tungsten-mogium");
  add_id("tungsten-mogium sword");
  set_value(72200);
  set_size(19);
  set_weight(190);
  set_weapon_action("slash");
  set_weapon_skill("combat/sharp/small");
  set_short("A tungsten-mogium sword");
  set_long("A tungsten-mogium sword");
  set_min_damage(19);
  set_max_damage(190);
  set_hit_bonus(38);
}
