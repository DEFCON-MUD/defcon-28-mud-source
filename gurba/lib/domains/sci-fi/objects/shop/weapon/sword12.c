inherit "/std/weapon";

#include "../../../domain.h"

void setup(void) {
  set_id("titanium-carbide sword");
  add_id("sword");
  add_id("titanium-carbide");
  add_id("titanium-carbide sword");
  set_value(28800);
  set_size(12);
  set_weight(120);
  set_weapon_action("slash");
  set_weapon_skill("combat/sharp/small");
  set_short("A titanium-carbide sword");
  set_long("A titanium-carbide sword");
  set_min_damage(12);
  set_max_damage(120);
  set_hit_bonus(24);
}
