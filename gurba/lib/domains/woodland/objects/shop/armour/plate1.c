inherit "/std/armor";

#include "../../../domain.h"

void setup(void) {
  set_id("bronze plate");
  add_id("bronze");
  add_id("armour");  add_id("plate");
  set_ac(1);
  set_value(200);
  set_size(1);
  set_weight(10);
  set_slot("torso");
  set_short("A bronze plate");
  set_long("A bronze plate");
}
