inherit "/std/weapon";

#include "../../../domain.h"

void setup(void) {
  set_id("iron sword");
  add_id("sword");
  add_id("iron");
  add_id("iron sword");
  set_value(800);
  set_size(2);
  set_weight(20);
  set_weapon_action("slash");
  set_weapon_skill("combat/sharp/small");
  set_short("A iron sword");
  set_long("A iron sword");
  set_min_damage(2);
  set_max_damage(20);
  set_hit_bonus(4);
}
