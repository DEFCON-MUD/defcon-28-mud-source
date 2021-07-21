inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("lead helmet");
  add_id("lead");
  add_id("armour");  add_id("helmet");
  set_ac(4);
  set_value(3200);
  set_size(4);
  set_weight(40);
  set_slot("head");
  set_short("A lead helmet");
  set_long("A lead helmet");
}
