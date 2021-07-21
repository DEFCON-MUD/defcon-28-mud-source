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
  add_item(DIR + "/objects/shop/armour/armour19", 10);
  add_item(DIR + "/objects/shop/armour/armour20", 10);
  add_item(DIR + "/objects/shop/armour/boots19", 10);
  add_item(DIR + "/objects/shop/armour/boots20", 10);
  add_item(DIR + "/objects/shop/armour/bracers19", 10);
  add_item(DIR + "/objects/shop/armour/bracers20", 10);
  add_item(DIR + "/objects/shop/armour/faulds19", 10);
  add_item(DIR + "/objects/shop/armour/faulds20", 10);
  add_item(DIR + "/objects/shop/armour/gloves19", 10);
  add_item(DIR + "/objects/shop/armour/gloves20", 10);
  add_item(DIR + "/objects/shop/armour/gorget19", 10);
  add_item(DIR + "/objects/shop/armour/gorget20", 10);
  add_item(DIR + "/objects/shop/armour/guantlets19", 10);
  add_item(DIR + "/objects/shop/armour/guantlets20", 10);
  add_item(DIR + "/objects/shop/armour/helmet19", 10);
  add_item(DIR + "/objects/shop/armour/helmet20", 10);
  add_item(DIR + "/objects/shop/armour/plate19", 10);
  add_item(DIR + "/objects/shop/armour/plate20", 10);
  add_item(DIR + "/objects/shop/armour/ring19", 10);
  add_item(DIR + "/objects/shop/armour/ring20", 10);
}
