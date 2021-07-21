inherit "/std/weapon";

#include "../../../domain.h"

void setup(void) {
  set_id("mogium-titanium sword");
  add_id("sword");
  add_id("mogium-titanium");
  add_id("mogium-titanium sword");
  set_value(64800);
  set_size(18);
  set_weight(180);
  set_weapon_action("slash");
  set_weapon_skill("combat/sharp/small");
  set_short("A mogium-titanium sword");
  set_long("A mogium-titanium sword");
  set_min_damage(18);
  set_max_damage(180);
  set_hit_bonus(36);
}
