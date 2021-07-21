inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("gold helmet");
  add_id("gold");
  add_id("armour");  add_id("helmet");
  set_ac(3);
  set_value(1800);
  set_size(3);
  set_weight(30);
  set_slot("head");
  set_short("A gold helmet");
  set_long("A gold helmet");
}
