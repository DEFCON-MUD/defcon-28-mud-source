inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("aluminum gloves");
  add_id("aluminum");
  add_id("armour");  add_id("gloves");
  set_ac(5);
  set_value(5000);
  set_size(5);
  set_weight(50);
  set_slot("hands");
  set_short("A aluminum gloves");
  set_long("A aluminum gloves");
}
