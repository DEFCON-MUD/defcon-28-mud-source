inherit "/std/vendor";

#include "../domain.h"

void setup(void) {
  set_name("Autodoc");
add_id("auto");
add_id("doc");
add_id("autodoc");
  set_short( "Autodoc" );
  set_long( "This is a robot arm, it looks like it has seen some better days. It is attached to the ceiling. It might be leaking hyradulic fluid." );

  set_restock_delay(600);
  set_will_buy(0);

  set_gender("other");
  set_race("robot");

  set_level(40);

  add_item(DIR + "/objects/energy", 100);
  add_item(DIR + "/objects/str_potion", 10);
  add_item(DIR + "/objects/dex_potion", 10);
  add_item(DIR + "/objects/wis_potion", 10);
  add_item(DIR + "/objects/cha_potion", 10);
  add_item(DIR + "/objects/con_potion", 10);
  add_item(DIR + "/objects/int_potion", 10);
  add_item(DIR + "/objects/blade", 10);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 100);
  set_skill("combat/defense", 100);
}
