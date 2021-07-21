inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("gold ring");
  add_id("gold");
  add_id("armour");  add_id("ring");
  set_ac(3);
  set_value(1800);
  set_size(3);
  set_weight(30);
  set_slot("finger");
  set_short("A gold ring");
  set_long("A gold ring");
}
