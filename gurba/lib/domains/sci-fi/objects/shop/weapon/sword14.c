inherit "/std/weapon";

#include "../../../domain.h"

void setup(void) {
  set_id("aluminum-unobtainium sword");
  add_id("sword");
  add_id("aluminum-unobtainium");
  add_id("aluminum-unobtainium sword");
  set_value(39200);
  set_size(14);
  set_weight(140);
  set_weapon_action("slash");
  set_weapon_skill("combat/sharp/small");
  set_short("A aluminum-unobtainium sword");
  set_long("A aluminum-unobtainium sword");
  set_min_damage(14);
  set_max_damage(140);
  set_hit_bonus(28);
}
