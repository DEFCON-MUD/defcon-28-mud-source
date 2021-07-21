inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("bronze ring");
  add_id("bronze");
  add_id("armour");  add_id("ring");
  set_ac(1);
  set_value(200);
  set_size(1);
  set_weight(10);
  set_slot("finger");
  set_short("A bronze ring");
  set_long("A bronze ring");
}
