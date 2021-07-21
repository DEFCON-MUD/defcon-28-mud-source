inherit "/std/weapon";

#include "../../../domain.h"

void setup(void) {
  set_id("titanium-unobtanium sword");
  add_id("sword");
  add_id("titanium-unobtanium");
  add_id("titanium-unobtanium sword");
  set_value(51200);
  set_size(16);
  set_weight(160);
  set_weapon_action("slash");
  set_weapon_skill("combat/sharp/small");
  set_short("A titanium-unobtanium sword");
  set_long("A titanium-unobtanium sword");
  set_min_damage(16);
  set_max_damage(160);
  set_hit_bonus(32);
}
