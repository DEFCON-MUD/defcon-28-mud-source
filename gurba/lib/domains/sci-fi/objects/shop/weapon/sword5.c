inherit "/std/weapon";

#include "../../../domain.h"

void setup(void) {
  set_id("aluminum sword");
  add_id("sword");
  add_id("aluminum");
  add_id("aluminum sword");
  set_value(5000);
  set_size(5);
  set_weight(50);
  set_weapon_action("slash");
  set_weapon_skill("combat/sharp/small");
  set_short("A aluminum sword");
  set_long("A aluminum sword");
  set_min_damage(5);
  set_max_damage(50);
  set_hit_bonus(10);
}
