inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("iron boots");
  add_id("iron");
  add_id("armour");  add_id("boots");
  set_ac(2);
  set_value(800);
  set_size(2);
  set_weight(20);
  set_slot("feet");
  set_short("A iron boots");
  set_long("A iron boots");
}
