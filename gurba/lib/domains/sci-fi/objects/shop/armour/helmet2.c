inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("iron helmet");
  add_id("iron");
  add_id("armour");  add_id("helmet");
  set_ac(2);
  set_value(800);
  set_size(2);
  set_weight(20);
  set_slot("head");
  set_short("A iron helmet");
  set_long("A iron helmet");
}
