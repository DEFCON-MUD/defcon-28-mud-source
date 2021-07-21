inherit "/std/weapon";

#include "../../../domain.h"

void setup(void) {
  set_id("mogium-unobtanium sword");
  add_id("sword");
  add_id("mogium-unobtanium");
  add_id("mogium-unobtanium sword");
  set_value(80000);
  set_size(20);
  set_weight(200);
  set_weapon_action("slash");
  set_weapon_skill("combat/sharp/small");
  set_short("A mogium-unobtanium sword");
  set_long("A mogium-unobtanium sword");
  set_min_damage(20);
  set_max_damage(200);
  set_hit_bonus(40);
}
