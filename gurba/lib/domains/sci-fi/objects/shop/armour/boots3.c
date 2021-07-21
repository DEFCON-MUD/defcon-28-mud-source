inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("gold boots");
  add_id("gold");
  add_id("armour");  add_id("boots");
  set_ac(3);
  set_value(1800);
  set_size(3);
  set_weight(30);
  set_slot("feet");
  set_short("A gold boots");
  set_long("A gold boots");
}
