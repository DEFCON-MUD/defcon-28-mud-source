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
  add_item(DIR + "/objects/shop/armour/armour15", 10);
  add_item(DIR + "/objects/shop/armour/armour16", 10);
  add_item(DIR + "/objects/shop/armour/boots15", 10);
  add_item(DIR + "/objects/shop/armour/boots16", 10);
  add_item(DIR + "/objects/shop/armour/bracers15", 10);
  add_item(DIR + "/objects/shop/armour/bracers16", 10);
  add_item(DIR + "/objects/shop/armour/faulds15", 10);
  add_item(DIR + "/objects/shop/armour/faulds16", 10);
  add_item(DIR + "/objects/shop/armour/gloves15", 10);
  add_item(DIR + "/objects/shop/armour/gloves16", 10);
  add_item(DIR + "/objects/shop/armour/gorget15", 10);
  add_item(DIR + "/objects/shop/armour/gorget16", 10);
  add_item(DIR + "/objects/shop/armour/guantlets15", 10);
  add_item(DIR + "/objects/shop/armour/guantlets16", 10);
  add_item(DIR + "/objects/shop/armour/helmet15", 10);
  add_item(DIR + "/objects/shop/armour/helmet16", 10);
  add_item(DIR + "/objects/shop/armour/plate15", 10);
  add_item(DIR + "/objects/shop/armour/plate16", 10);
  add_item(DIR + "/objects/shop/armour/ring15", 10);
  add_item(DIR + "/objects/shop/armour/ring16", 10);
}
