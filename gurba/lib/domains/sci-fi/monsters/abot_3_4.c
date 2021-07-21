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
  add_item(DIR + "/objects/shop/armour/armour3", 10);
  add_item(DIR + "/objects/shop/armour/armour4", 10);
  add_item(DIR + "/objects/shop/armour/boots3", 10);
  add_item(DIR + "/objects/shop/armour/boots4", 10);
  add_item(DIR + "/objects/shop/armour/bracers3", 10);
  add_item(DIR + "/objects/shop/armour/bracers4", 10);
  add_item(DIR + "/objects/shop/armour/faulds3", 10);
  add_item(DIR + "/objects/shop/armour/faulds4", 10);
  add_item(DIR + "/objects/shop/armour/gloves3", 10);
  add_item(DIR + "/objects/shop/armour/gloves4", 10);
  add_item(DIR + "/objects/shop/armour/gorget3", 10);
  add_item(DIR + "/objects/shop/armour/gorget4", 10);
  add_item(DIR + "/objects/shop/armour/guantlets3", 10);
  add_item(DIR + "/objects/shop/armour/guantlets4", 10);
  add_item(DIR + "/objects/shop/armour/helmet3", 10);
  add_item(DIR + "/objects/shop/armour/helmet4", 10);
  add_item(DIR + "/objects/shop/armour/plate3", 10);
  add_item(DIR + "/objects/shop/armour/plate4", 10);
  add_item(DIR + "/objects/shop/armour/ring3", 10);
  add_item(DIR + "/objects/shop/armour/ring4", 10);
}
