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
  add_item(DIR + "/objects/shop/weapon/sword1", 10);
  add_item(DIR + "/objects/shop/weapon/sword2", 10);
  add_item(DIR + "/objects/shop/weapon/sword3", 10);
  add_item(DIR + "/objects/shop/weapon/sword4", 10);
  add_item(DIR + "/objects/shop/weapon/sword5", 10);
  add_item(DIR + "/objects/shop/weapon/sword6", 10);
  add_item(DIR + "/objects/shop/weapon/sword7", 10);
  add_item(DIR + "/objects/shop/weapon/sword8", 10);
  add_item(DIR + "/objects/shop/weapon/sword9", 10);
  add_item(DIR + "/objects/shop/weapon/sword10", 10);
  add_item(DIR + "/objects/shop/weapon/sword11", 10);
  add_item(DIR + "/objects/shop/weapon/sword12", 10);
  add_item(DIR + "/objects/shop/weapon/sword13", 10);
  add_item(DIR + "/objects/shop/weapon/sword14", 10);
  add_item(DIR + "/objects/shop/weapon/sword15", 10);
  add_item(DIR + "/objects/shop/weapon/sword16", 10);
  add_item(DIR + "/objects/shop/weapon/sword17", 10);
  add_item(DIR + "/objects/shop/weapon/sword18", 10);
  add_item(DIR + "/objects/shop/weapon/sword19", 10);
  add_item(DIR + "/objects/shop/weapon/sword20", 10);
}
