inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("aluminum helmet");
  add_id("aluminum");
  add_id("armour");  add_id("helmet");
  set_ac(5);
  set_value(5000);
  set_size(5);
  set_weight(50);
  set_slot("head");
  set_short("A aluminum helmet");
  set_long("A aluminum helmet");
}
