inherit "/std/weapon";

#include "../../../domain.h"

void setup(void) {
  set_id("bronze sword");
  add_id("sword");
  add_id("bronze");
  add_id("bronze sword");
  set_value(200);
  set_size(1);
  set_weight(10);
  set_weapon_action("slash");
  set_weapon_skill("combat/sharp/small");
  set_short("A bronze sword");
  set_long("A bronze sword");
  set_min_damage(1);
  set_max_damage(10);
  set_hit_bonus(2);
}
