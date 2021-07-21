inherit "/std/weapon";

#include "../../../domain.h"

void setup(void) {
  set_id("mithril-titanium sword");
  add_id("sword");
  add_id("mithril-titanium");
  add_id("mithril-titanium sword");
  set_value(20000);
  set_size(10);
  set_weight(100);
  set_weapon_action("slash");
  set_weapon_skill("combat/sharp/small");
  set_short("A mithril-titanium sword");
  set_long("A mithril-titanium sword");
  set_min_damage(10);
  set_max_damage(100);
  set_hit_bonus(20);
}
