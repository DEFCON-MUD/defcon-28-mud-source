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
  add_item(DIR + "/objects/shop/armour/armour17", 10);
  add_item(DIR + "/objects/shop/armour/armour18", 10);
  add_item(DIR + "/objects/shop/armour/boots17", 10);
  add_item(DIR + "/objects/shop/armour/boots18", 10);
  add_item(DIR + "/objects/shop/armour/bracers17", 10);
  add_item(DIR + "/objects/shop/armour/bracers18", 10);
  add_item(DIR + "/objects/shop/armour/faulds17", 10);
  add_item(DIR + "/objects/shop/armour/faulds18", 10);
  add_item(DIR + "/objects/shop/armour/gloves17", 10);
  add_item(DIR + "/objects/shop/armour/gloves18", 10);
  add_item(DIR + "/objects/shop/armour/gorget17", 10);
  add_item(DIR + "/objects/shop/armour/gorget18", 10);
  add_item(DIR + "/objects/shop/armour/guantlets17", 10);
  add_item(DIR + "/objects/shop/armour/guantlets18", 10);
  add_item(DIR + "/objects/shop/armour/helmet17", 10);
  add_item(DIR + "/objects/shop/armour/helmet18", 10);
  add_item(DIR + "/objects/shop/armour/plate17", 10);
  add_item(DIR + "/objects/shop/armour/plate18", 10);
  add_item(DIR + "/objects/shop/armour/ring17", 10);
  add_item(DIR + "/objects/shop/armour/ring18", 10);
}
