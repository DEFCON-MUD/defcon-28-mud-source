inherit "/std/weapon";

#include "../../../domain.h"

void setup(void) {
  set_id("mithril sword");
  add_id("sword");
  add_id("mithril");
  add_id("mithril sword");
  set_value(12800);
  set_size(8);
  set_weight(80);
  set_weapon_action("slash");
  set_weapon_skill("combat/sharp/small");
  set_short("A mithril sword");
  set_long("A mithril sword");
  set_min_damage(8);
  set_max_damage(80);
  set_hit_bonus(16);
}
