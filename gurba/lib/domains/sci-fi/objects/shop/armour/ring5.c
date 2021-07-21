inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("aluminum ring");
  add_id("aluminum");
  add_id("armour");  add_id("ring");
  set_ac(5);
  set_value(5000);
  set_size(5);
  set_weight(50);
  set_slot("finger");
  set_short("A aluminum ring");
  set_long("A aluminum ring");
}
