inherit "/std/weapon";

#include "../../../domain.h"

void setup(void) {
  set_id("iron-carbide sword");
  add_id("sword");
  add_id("iron-carbide");
  add_id("iron-carbide sword");
  set_value(9800);
  set_size(7);
  set_weight(70);
  set_weapon_action("slash");
  set_weapon_skill("combat/sharp/small");
  set_short("A iron-carbide sword");
  set_long("A iron-carbide sword");
  set_min_damage(7);
  set_max_damage(70);
  set_hit_bonus(14);
}
