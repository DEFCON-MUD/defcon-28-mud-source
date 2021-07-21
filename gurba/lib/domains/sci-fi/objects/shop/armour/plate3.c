inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("gold plate");
  add_id("gold");
  add_id("armour");  add_id("plate");
  set_ac(3);
  set_value(1800);
  set_size(3);
  set_weight(30);
  set_slot("torso");
  set_short("A gold plate");
  set_long("A gold plate");
}
