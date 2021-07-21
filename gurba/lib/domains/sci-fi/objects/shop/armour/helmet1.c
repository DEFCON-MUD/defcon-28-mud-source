inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("bronze helmet");
  add_id("bronze");
  add_id("armour");  add_id("helmet");
  set_ac(1);
  set_value(200);
  set_size(1);
  set_weight(10);
  set_slot("head");
  set_short("A bronze helmet");
  set_long("A bronze helmet");
}
