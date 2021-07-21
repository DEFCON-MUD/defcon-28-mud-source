inherit "/std/weapon";

#include "../../../domain.h"

void setup(void) {
  set_id("tungsten-unobtanium sword");
  add_id("sword");
  add_id("tungsten-unobtanium");
  add_id("tungsten-unobtanium sword");
  set_value(45000);
  set_size(15);
  set_weight(150);
  set_weapon_action("slash");
  set_weapon_skill("combat/sharp/small");
  set_short("A tungsten-unobtanium sword");
  set_long("A tungsten-unobtanium sword");
  set_min_damage(15);
  set_max_damage(150);
  set_hit_bonus(30);
}
