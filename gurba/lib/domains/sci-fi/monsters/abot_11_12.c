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
  add_item(DIR + "/objects/shop/armour/armour11", 10);
  add_item(DIR + "/objects/shop/armour/armour12", 10);
  add_item(DIR + "/objects/shop/armour/boots11", 10);
  add_item(DIR + "/objects/shop/armour/boots12", 10);
  add_item(DIR + "/objects/shop/armour/bracers11", 10);
  add_item(DIR + "/objects/shop/armour/bracers12", 10);
  add_item(DIR + "/objects/shop/armour/faulds11", 10);
  add_item(DIR + "/objects/shop/armour/faulds12", 10);
  add_item(DIR + "/objects/shop/armour/gloves11", 10);
  add_item(DIR + "/objects/shop/armour/gloves12", 10);
  add_item(DIR + "/objects/shop/armour/gorget11", 10);
  add_item(DIR + "/objects/shop/armour/gorget12", 10);
  add_item(DIR + "/objects/shop/armour/guantlets11", 10);
  add_item(DIR + "/objects/shop/armour/guantlets12", 10);
  add_item(DIR + "/objects/shop/armour/helmet11", 10);
  add_item(DIR + "/objects/shop/armour/helmet12", 10);
  add_item(DIR + "/objects/shop/armour/plate11", 10);
  add_item(DIR + "/objects/shop/armour/plate12", 10);
  add_item(DIR + "/objects/shop/armour/ring11", 10);
  add_item(DIR + "/objects/shop/armour/ring12", 10);
}
