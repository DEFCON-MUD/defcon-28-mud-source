inherit "/std/weapon";

#include "../../../domain.h"

void setup(void) {
  set_id("lead sword");
  add_id("sword");
  add_id("lead");
  add_id("lead sword");
  set_value(3200);
  set_size(4);
  set_weight(40);
  set_weapon_action("slash");
  set_weapon_skill("combat/sharp/small");
  set_short("A lead sword");
  set_long("A lead sword");
  set_min_damage(4);
  set_max_damage(40);
  set_hit_bonus(8);
}
