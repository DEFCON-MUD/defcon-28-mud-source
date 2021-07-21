inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("gold gloves");
  add_id("gold");
  add_id("armour");  add_id("gloves");
  set_ac(3);
  set_value(1800);
  set_size(3);
  set_weight(30);
  set_slot("hands");
  set_short("A gold gloves");
  set_long("A gold gloves");
}
