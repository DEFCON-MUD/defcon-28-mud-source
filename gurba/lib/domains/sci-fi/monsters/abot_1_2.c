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
  add_item(DIR + "/objects/shop/armour/armour1", 10);
  add_item(DIR + "/objects/shop/armour/armour2", 10);
  add_item(DIR + "/objects/shop/armour/boots1", 10);
  add_item(DIR + "/objects/shop/armour/boots2", 10);
  add_item(DIR + "/objects/shop/armour/bracers1", 10);
  add_item(DIR + "/objects/shop/armour/bracers2", 10);
  add_item(DIR + "/objects/shop/armour/faulds1", 10);
  add_item(DIR + "/objects/shop/armour/faulds2", 10);
  add_item(DIR + "/objects/shop/armour/gloves1", 10);
  add_item(DIR + "/objects/shop/armour/gloves2", 10);
  add_item(DIR + "/objects/shop/armour/gorget1", 10);
  add_item(DIR + "/objects/shop/armour/gorget2", 10);
  add_item(DIR + "/objects/shop/armour/guantlets1", 10);
  add_item(DIR + "/objects/shop/armour/guantlets2", 10);
  add_item(DIR + "/objects/shop/armour/helmet1", 10);
  add_item(DIR + "/objects/shop/armour/helmet2", 10);
  add_item(DIR + "/objects/shop/armour/plate1", 10);
  add_item(DIR + "/objects/shop/armour/plate2", 10);
  add_item(DIR + "/objects/shop/armour/ring1", 10);
  add_item(DIR + "/objects/shop/armour/ring2", 10);
}
