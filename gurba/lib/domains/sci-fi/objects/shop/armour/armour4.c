inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("lead armour");
  add_id("lead");
  add_id("armour");  add_id("armour");
  set_ac(4);
  set_value(3200);
  set_size(4);
  set_weight(40);
  set_slot("body");
  set_short("A lead armour");
  set_long("A lead armour");
}
