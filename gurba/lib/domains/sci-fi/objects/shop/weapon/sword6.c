inherit "/std/weapon";

#include "../../../domain.h"

void setup(void) {
  set_id("tungsten sword");
  add_id("sword");
  add_id("tungsten");
  add_id("tungsten sword");
  set_value(7200);
  set_size(6);
  set_weight(60);
  set_weapon_action("slash");
  set_weapon_skill("combat/sharp/small");
  set_short("A tungsten sword");
  set_long("A tungsten sword");
  set_min_damage(6);
  set_max_damage(60);
  set_hit_bonus(12);
}
