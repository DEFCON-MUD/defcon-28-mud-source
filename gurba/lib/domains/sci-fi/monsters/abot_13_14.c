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
  add_item(DIR + "/objects/shop/armour/armour13", 10);
  add_item(DIR + "/objects/shop/armour/armour14", 10);
  add_item(DIR + "/objects/shop/armour/boots13", 10);
  add_item(DIR + "/objects/shop/armour/boots14", 10);
  add_item(DIR + "/objects/shop/armour/bracers13", 10);
  add_item(DIR + "/objects/shop/armour/bracers14", 10);
  add_item(DIR + "/objects/shop/armour/faulds13", 10);
  add_item(DIR + "/objects/shop/armour/faulds14", 10);
  add_item(DIR + "/objects/shop/armour/gloves13", 10);
  add_item(DIR + "/objects/shop/armour/gloves14", 10);
  add_item(DIR + "/objects/shop/armour/gorget13", 10);
  add_item(DIR + "/objects/shop/armour/gorget14", 10);
  add_item(DIR + "/objects/shop/armour/guantlets13", 10);
  add_item(DIR + "/objects/shop/armour/guantlets14", 10);
  add_item(DIR + "/objects/shop/armour/helmet13", 10);
  add_item(DIR + "/objects/shop/armour/helmet14", 10);
  add_item(DIR + "/objects/shop/armour/plate13", 10);
  add_item(DIR + "/objects/shop/armour/plate14", 10);
  add_item(DIR + "/objects/shop/armour/ring13", 10);
  add_item(DIR + "/objects/shop/armour/ring14", 10);
}
