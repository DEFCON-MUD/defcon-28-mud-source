inherit "/std/vendor";

#include "../domain.h"

void setup(void) {
  set_name("Autobot");
  set_short( "Autobot" );
  set_long( "This is a robot arm, it looks like it has seen some better days. It is attached to the ceiling. It might be leaking hyradulic fluid." );

  set_gender("other");
  set_race("robot");

  set_level(40);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 200);
  set_skill("combat/defense", 200);
  set_restock_delay(600);
  set_will_buy(0);
  add_item(DIR + "/objects/shop/armour/armour9", 10);
  add_item(DIR + "/objects/shop/armour/armour10", 10);
  add_item(DIR + "/objects/shop/armour/boots9", 10);
  add_item(DIR + "/objects/shop/armour/boots10", 10);
  add_item(DIR + "/objects/shop/armour/bracers9", 10);
  add_item(DIR + "/objects/shop/armour/bracers10", 10);
  add_item(DIR + "/objects/shop/armour/faulds9", 10);
  add_item(DIR + "/objects/shop/armour/faulds10", 10);
  add_item(DIR + "/objects/shop/armour/gloves9", 10);
  add_item(DIR + "/objects/shop/armour/gloves10", 10);
  add_item(DIR + "/objects/shop/armour/gorget9", 10);
  add_item(DIR + "/objects/shop/armour/gorget10", 10);
  add_item(DIR + "/objects/shop/armour/guantlets9", 10);
  add_item(DIR + "/objects/shop/armour/guantlets10", 10);
  add_item(DIR + "/objects/shop/armour/helmet9", 10);
  add_item(DIR + "/objects/shop/armour/helmet10", 10);
  add_item(DIR + "/objects/shop/armour/plate9", 10);
  add_item(DIR + "/objects/shop/armour/plate10", 10);
  add_item(DIR + "/objects/shop/armour/ring9", 10);
  add_item(DIR + "/objects/shop/armour/ring10", 10);
}
