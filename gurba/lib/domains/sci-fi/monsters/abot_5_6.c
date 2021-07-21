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
  add_item(DIR + "/objects/shop/armour/armour5", 10);
  add_item(DIR + "/objects/shop/armour/armour6", 10);
  add_item(DIR + "/objects/shop/armour/boots5", 10);
  add_item(DIR + "/objects/shop/armour/boots6", 10);
  add_item(DIR + "/objects/shop/armour/bracers5", 10);
  add_item(DIR + "/objects/shop/armour/bracers6", 10);
  add_item(DIR + "/objects/shop/armour/faulds5", 10);
  add_item(DIR + "/objects/shop/armour/faulds6", 10);
  add_item(DIR + "/objects/shop/armour/gloves5", 10);
  add_item(DIR + "/objects/shop/armour/gloves6", 10);
  add_item(DIR + "/objects/shop/armour/gorget5", 10);
  add_item(DIR + "/objects/shop/armour/gorget6", 10);
  add_item(DIR + "/objects/shop/armour/guantlets5", 10);
  add_item(DIR + "/objects/shop/armour/guantlets6", 10);
  add_item(DIR + "/objects/shop/armour/helmet5", 10);
  add_item(DIR + "/objects/shop/armour/helmet6", 10);
  add_item(DIR + "/objects/shop/armour/plate5", 10);
  add_item(DIR + "/objects/shop/armour/plate6", 10);
  add_item(DIR + "/objects/shop/armour/ring5", 10);
  add_item(DIR + "/objects/shop/armour/ring6", 10);
}
