inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("gold armour");
  add_id("gold");
  add_id("armour");  add_id("armour");
  set_ac(3);
  set_value(1800);
  set_size(3);
  set_weight(30);
  set_slot("body");
  set_short("A gold armour");
  set_long("A gold armour");
}
