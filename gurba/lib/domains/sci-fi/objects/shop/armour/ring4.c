inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("lead ring");
  add_id("lead");
  add_id("armour");  add_id("ring");
  set_ac(4);
  set_value(3200);
  set_size(4);
  set_weight(40);
  set_slot("finger");
  set_short("A lead ring");
  set_long("A lead ring");
}
