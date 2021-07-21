inherit "/std/weapon";

#include "../../../domain.h"

void setup(void) {
  set_id("ubobtanium sword");
  add_id("sword");
  add_id("ubobtanium");
  add_id("ubobtanium sword");
  set_value(33800);
  set_size(13);
  set_weight(130);
  set_weapon_action("slash");
  set_weapon_skill("combat/sharp/small");
  set_short("A ubobtanium sword");
  set_long("A ubobtanium sword");
  set_min_damage(13);
  set_max_damage(130);
  set_hit_bonus(26);
}
