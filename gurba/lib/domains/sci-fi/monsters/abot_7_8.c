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
  add_item(DIR + "/objects/shop/armour/armour7", 10);
  add_item(DIR + "/objects/shop/armour/armour8", 10);
  add_item(DIR + "/objects/shop/armour/boots7", 10);
  add_item(DIR + "/objects/shop/armour/boots8", 10);
  add_item(DIR + "/objects/shop/armour/bracers7", 10);
  add_item(DIR + "/objects/shop/armour/bracers8", 10);
  add_item(DIR + "/objects/shop/armour/faulds7", 10);
  add_item(DIR + "/objects/shop/armour/faulds8", 10);
  add_item(DIR + "/objects/shop/armour/gloves7", 10);
  add_item(DIR + "/objects/shop/armour/gloves8", 10);
  add_item(DIR + "/objects/shop/armour/gorget7", 10);
  add_item(DIR + "/objects/shop/armour/gorget8", 10);
  add_item(DIR + "/objects/shop/armour/guantlets7", 10);
  add_item(DIR + "/objects/shop/armour/guantlets8", 10);
  add_item(DIR + "/objects/shop/armour/helmet7", 10);
  add_item(DIR + "/objects/shop/armour/helmet8", 10);
  add_item(DIR + "/objects/shop/armour/plate7", 10);
  add_item(DIR + "/objects/shop/armour/plate8", 10);
  add_item(DIR + "/objects/shop/armour/ring7", 10);
  add_item(DIR + "/objects/shop/armour/ring8", 10);
}
