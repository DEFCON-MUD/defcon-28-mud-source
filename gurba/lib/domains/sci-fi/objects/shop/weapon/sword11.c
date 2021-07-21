inherit "/std/weapon";

#include "../../../domain.h"

void setup(void) {
  set_id("aluminum-titanium sword");
  add_id("sword");
  add_id("aluminum-titanium");
  add_id("aluminum-titanium sword");
  set_value(24200);
  set_size(11);
  set_weight(110);
  set_weapon_action("slash");
  set_weapon_skill("combat/sharp/small");
  set_short("A aluminum-titanium sword");
  set_long("A aluminum-titanium sword");
  set_min_damage(11);
  set_max_damage(110);
  set_hit_bonus(22);
}
