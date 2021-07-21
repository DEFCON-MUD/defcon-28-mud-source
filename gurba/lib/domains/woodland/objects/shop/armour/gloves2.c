inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("iron gloves");
  add_id("iron");
  add_id("armour");  add_id("gloves");
  set_ac(2);
  set_value(800);
  set_size(2);
  set_weight(20);
  set_slot("hands");
  set_short("A iron gloves");
  set_long("A iron gloves");
}
